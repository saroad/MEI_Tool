#NoTrayIcon

#include <Misc.au3>
#include <MsgBoxConstants.au3>
#include <GuiEdit.au3>
#include <DataStructures.au3>
#include <FuncLib.au3>
#include <AutoItConstants.au3>

#include <WinAPISys.au3>

Opt("CaretCoordMode", 1)
;Opt("WinTitleMatchMode", 4)
;opt("MouseCoordMode", 2)

;Local $hDLL = DllOpen("user32.dll")

Global $IP_ADDRESS="127.0.0.1"
Global $PORT=1

Global Const $blockSize=50
Global $TCPConnect
Global $GUIHandle
Global $WinHandle
Global $inputLength=0
Global $inputCapacity=$blockSize
Global $inputString[$inputCapacity][2]
Global $pos=$inputLength
Global $check=True

HotKeySet("{ESC}", "start")

While $check
	Sleep(10)
WEnd

Func getInput()

	Local $char, $block[$blockSize][2]

	While 1

		$char=isCharPressed()

		If Not($char) Then
			ContinueLoop
		EndIf

		Switch $char

			Case "Enter"
				ExitLoop
			Case "Left"
				If $pos>0 Then
					$pos-=1
				EndIf
			Case "Right"
				If $pos<$inputLength Then
					$pos+=1
				EndIf
			Case "-1"
				If $pos>0 Then
					$inputString[$pos-1][0]=2*$inputCapacity
					_ArraySort($inputString,0,0,$inputLength-1)
					$inputString[$inputLength-1][0]=Null
					$inputString[$inputLength-1][1]=Null
					$inputLength-=1
					$pos-=1
				EndIf
			Case "+1"
				If $pos<$inputLength Then
					$inputString[$pos][0]=2*$inputCapacity
					_ArraySort($inputString,0,0,$inputLength-1)
					$inputString[$inputLength-1][0]=Null
					$inputString[$inputLength-1][1]=Null
					$inputLength-=1
				EndIf
			Case Else
				If $inputLength=$inputCapacity Then
					_ArrayConcatenate($inputString,$block)
					$inputCapacity+=$blockSize
				EndIf
				If $pos=0 And $inputLength=0 Then
					$inputString[$inputLength][0]=0
					$inputString[$inputLength][1]=$char
					$pos+=1
					$inputLength+=1
				ElseIf $pos=0 Then
					$inputString[$inputLength][0]=$inputString[$pos][0]-1
					$inputString[$inputLength][1]=$char
					$pos+=1
					$inputLength+=1
					_ArraySort($inputString,0,0,$inputLength-1)
				ElseIf $pos=$inputLength Then
					$inputString[$inputLength][0]=$pos
					$inputString[$inputLength][1]=$char
					$pos+=1
					$inputLength+=1
				Else
					$inputString[$inputLength][0]=($inputString[$pos][0]+$inputString[$pos-1][0])/2
					$inputString[$inputLength][1]=$char
					$pos+=1
					$inputLength+=1
					_ArraySort($inputString,0,0,$inputLength-1)
				EndIf

		EndSwitch

	WEnd

	Local $input=_ArrayToString($inputString,"",0,$inputLength-1,"",1,1)

	Return $input

EndFunc

Func setConnection()

	TCPStartup()

	$TCPConnect = TCPConnect($IP_ADDRESS, $PORT)


	If $TCPConnect=-1 Then
		MsgBox(0,"Error in Application","Try Again..!!!")
		Exit
	EndIf

EndFunc

Func recieveData()

	Local $TCPRecieve

	Do
		$TCPRecieve= TCPRecv($TCPConnect,1000000)
	Until $TCPRecieve<>""

	Return $TCPRecieve

EndFunc

Func sendData($data)

	Local $len=StringLen($data)

	TCPSend($TCPConnect,String($len)&"@"&$data)

EndFunc

Func closeConnection()

	TCPCloseSocket($TCPConnect)
	TCPShutdown()

EndFunc

Func getGUIHandle()

	sendData("Okay")
	Return(HWnd(recieveData()))

EndFunc

Func positionGUI($hnd, $caretPos)

	;Local $caretPos=WinGetCaretPos()

	;WinMove(HWnd($hnd),"",$caretPos[0],$caretPos[1])
	WinMove(HWnd($hnd),"",0,0)
	;MsgBox(0,"","Activated1")

EndFunc

Func sendUserInput($input)

	Send(getUndoStr(1))
	sendData($input)
	recieveData()

EndFunc

Func confirmChoice()

	While 1

		Sleep(5)
		If isCharPressed()="Enter" Then
			sendData("Okay")
			recieveData()
			ExitLoop
		ElseIf WinActive($WinHandle) Then
			ConsoleWrite("WinActive" & @LF)
			sendData("Again")
			recieveData()
			interactWithUser()
			ExitLoop
		EndIf

	WEnd

	Return

EndFunc

Func getUserChoice()

	sendData("Okay")
	$latex=recieveData()
	ConsoleWrite($latex)

	Return($latex)

EndFunc

Func pasteLatex($latex)

	While $inputLength>$pos
		Send("{RIGHT}")
		$pos+=1
	WEnd

	Send(getUndoStr($inputLength))
	Send(getSendStr($latex))

	sendData("Okay")
	recieveData();

EndFunc

Func getUndoStr($len)

	Local $str="{BS " & String($len) & "}"

	Return($str)

EndFunc


Func interactWithUser()

	sendUserInput(getInput())
	ConsoleWrite("sendUserInput(getInput())" & @LF)
	Sleep(20)

	WinActivate($GUIHandle)
	confirmChoice()
	ConsoleWrite("confirmChoice " & @LF)

	Return

EndFunc

Func start()

	$check=False

	$WinHandle=WinGetHandle("[Active]")

	setConnection()
	ConsoleWrite("setconnection" & @LF)

	$GUIHandle=getGUIHandle()
	ConsoleWrite("getGUIHandle" & @LF)

	;Local $caretPos
	;positionGUI($GUIHandle, $caretPos)
	WinActivate($WinHandle)
	ConsoleWrite("WinActivated" & @LF)

	interactWithUser()
	Sleep(5)

	WinActivate($WinHandle)
	pasteLatex(getUserChoice())
	ConsoleWrite("pasteLatex(getUserChoice())" & @LF)

	closeConnection()
	ConsoleWrite("closeConnection" & @LF)

EndFunc
