#include-once

#include <Misc.au3>
#include <MsgBoxConstants.au3>
#include <DataStructures.au3>
#include <AutoItConstants.au3>
#include <WinAPISys.au3>
#include <Array.au3>
#include <GuiEdit.au3>
#include <WinAPIvkeysConstants.au3>

Func isCharPressed()

	Local $hDLL = DllOpen("user32.dll")
	Local $char=Null
	Local $content[]=[8,9,13,32,37,38,39,40,46,186,187,188,189,190,191,192,219,220,221,222]
	Local $alpha[26], $num[10]
	Local $isShift, $isCapsLock

	For $i=0 to 25
		$alpha[$i]=65+$i
	Next

	For $i=0 to 9
		$num[$i]=48+$i
	Next

	_ArrayConcatenate($content,$alpha)
	_ArrayConcatenate($content,$num)

	For $j=0 To UBound($content)-1

		$i=$content[$j]

		If _IsPressed(Hex($i) ,$hDLL) Then

			If _IsPressed("10", $hDLL) Then
				$isShift=1
			Else
				$isShift=-1
			EndIf

			If BitAND(_WinAPI_GetKeyState($VK_CAPITAL), 1) Then
				$isCapsLock=1
			Else
				$isCapsLock=-1
			EndIf

			$char=getChar($i, $isShift, $isCapsLock)

			While _IsPressed(Hex($i),$hDLL)

				Sleep(2)
			WEnd

		EndIf

	Next

	DllClose($hDLL)

	Return $char

EndFunc

Func getSendStr($str)

	Local $aArray=StringToASCIIArray($str)
	Local $out=""
	For $j=0 To UBound($aArray)-1
		$out=$out & "{ASC " & $aArray[$j] & "}"
	Next

	Return($out)

EndFunc


Func getChar($j, $isShift, $isCapsLock)

	If $j>=48 And $j<=57 And $isShift=-1 Then
		Return (Chr($j))
	ElseIf $j>=65 And $j<=90 And $isShift*$isCapsLock=1 Then
		Return(StringLower(Chr($j)))
	ElseIf  $j>=65 And $j<=90 And $isShift*$isCapsLock=-1 Then
		Return (StringUpper(Chr($j)))
	EndIf

	Local $out

	Select
		Case $j=8
			$out="-1"
		Case $j=9
			$out=@TAB
		Case $j=13
			$out="Enter"
		Case $j=32
			$out=" "
		Case $j=37
			$out="Left"
		Case $j=38
			$out="Up"
		Case $j=39
			$out="Right"
		Case $j=40
			$out="Down"
		Case $j=46
			$out="+1"
		Case $j=186 And $isShift=-1
			$out=";"
		Case $j=187 And $isShift=-1
			$out="="
		Case $j=188 And $isShift=-1
			$out=","
		Case $j=189 And $isShift=-1
			$out="-"
		Case $j=190 And $isShift=-1
			$out="."
		Case $j=191 And $isShift=-1
			$out="/"
		Case $j=192 And $isShift=-1
			$out="`"
		Case $j=219 And $isShift=-1
			$out="["
		Case $j=220 And $isShift=-1
			$out="\"
		Case $j=221 And $isShift=-1
			$out="]"
		Case $j=222 And $isShift=-1
			$out="'"
		Case $j=186 And $isShift=1
			$out=":"
		Case $j=187 And $isShift=1
			$out="+"
		Case $j=188 And $isShift=1
			$out="<"
		Case $j=189 And $isShift=1
			$out="_"
		Case $j=190 And $isShift=1
			$out=">"
		Case $j=191 And $isShift=1
			$out="?"
		Case $j=192 And $isShift=1
			$out="~"
		Case $j=219 And $isShift=1
			$out="{"
		Case $j=220 And $isShift=1
			$out="|"
		Case $j=221 And $isShift=1
			$out="}"
		Case $j=222 And $isShift=1
			$out=Chr(34)
		Case $j=48 And $isShift=1
			$out=")"
		Case $j=49 And $isShift=1
			$out="!"
		Case $j=50 And $isShift=1
			$out="@"
		Case $j=51 And $isShift=1
			$out="#"
		Case $j=52 And $isShift=1
			$out="$"
		Case $j=53 And $isShift=1
			$out="%"
		Case $j=54 And $isShift=1
			$out="^"
		Case $j=55 And $isShift=1
			$out="&"
		Case $j=56 And $isShift=1
			$out="*"
		Case $j=57 And $isShift=1
			$out="("
		Case Else
			$out=Null
	EndSelect

	Return $out

EndFunc