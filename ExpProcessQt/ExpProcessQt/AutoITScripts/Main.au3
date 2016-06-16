

Global $check=True
Global $cProcessList
Global $sProcessList
Global $serverId
Global $clientId

HotKeySet("+{F4}", "BeginSession")
HotKeySet("+{F3}", "Close")
HotKeySet("+{F2}", "CloseExe")


While $check
	Sleep(10)
WEnd


Func BeginSession()

	CloseAll()

	$serverId=Run("C:\Users\Melanka Saroad\Desktop\Moratuwa Engineering\Semester5\Software Engineering Project\TestingCodes\ExpProcessQt\Win32\Debug\ExpProcessQt.exe")

	If Not($serverId) Then
		HandleError("Try again by pressing Shift + F4 (Server)")
		Return
	EndIf

	Sleep(1000)

	$cProcessList = ProcessList("ExpressionInput.exe")
	If $cProcessList[0][0]<1 Then
		HandleError("Try again by pressing Shift + F4 (Client)")
		Return
	EndIf

	$clientId=$cProcessList[1][1]

	ConsoleWrite("Server: "& $serverId & @LF)
	ConsoleWrite("Client: "& $clientId & @LF)

	While ProcessExists($serverId) And ProcessExists($clientId)
		Sleep(10)
	WEnd
	CloseExe()

	ConsoleWrite("Finished" & @LF)



EndFunc

Func Close()
	CloseExe()
	$check=False
EndFunc

Func HandleError($message)

	CloseExe()
	MsgBox(0, "Error", $message)

EndFunc

Func CloseExe()

	If $serverId And ProcessExists($serverId) Then
		ProcessClose($serverId)
	EndIf

	If $clientId And ProcessExists($clientId) Then
		ProcessClose($clientId)
	EndIf

	For $i=1 To $cProcessList[0][0]
		If ProcessExists($cProcessList[$i][1]) Then
			ProcessClose($cProcessList[$i][1])
		EndIf
	Next

EndFunc

Func CloseAll()

	$sProcessList = ProcessList("ExpProcessQt.exe")
	$cProcessList = ProcessList("ExpressionInput.exe")

	If $sProcessList[0][0]>0 Then
		For $i=1 To $cProcessList[0][0]
			If ProcessExists($sProcessList[$i][1]) Then
				ProcessClose($sProcessList[$i][1])
			EndIf
		Next
	EndIf

	If $cProcessList[0][0]>0 Then
		For $i=1 To $cProcessList[0][0]
			If ProcessExists($cProcessList[$i][1]) Then
				ProcessClose($cProcessList[$i][1])
			EndIf
		Next
	EndIf

EndFunc

