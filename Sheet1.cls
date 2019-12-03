VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "Sheet1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Private Sub Worksheet_Change(ByVal Target As Range)

    Dim KeyCells As Range
    Set KeyCells = Range("F:F")
    Dim val As String
    
If Not Application.Intersect(KeyCells, Range(Target.Address)) _
           Is Nothing Then
    val = Cells(Rows.Count, 6).End(xlUp).Value
    If val = "vendeg" Then
            Call Mail
        Else
           
    End If
        

End If
End Sub
Sub Mail()
    Dim OutApp As Object
    Dim OutMail As Object
    Dim strbody As String
    Dim vnev As String
    Dim vtnev As String
    Dim vdate As String
    
    vnev = Cells(Rows.Count, 3).End(xlUp).Value
    vtnev = Cells(Rows.Count, 5).End(xlUp).Value
    vdate = Cells(Rows.Count, 1).End(xlUp).Value & " " & Format(Cells(Rows.Count, 2).End(xlUp).Value, "h:m:s")
    Set OutApp = CreateObject("Outlook.Application")
    Set OutMail = OutApp.CreateItem(0)

    strbody = "Hello egy vendég belépett a szobába" & vbNewLine & vbNewLine & _
              "NÉV: " & vnev & vbNewLine & _
              "BEENGEDTE: " & vtnev & vbNewLine & _
              "EKKOR: " & vdate & vbNewLine & _
              "MINDENKI A SAJÁT VENDÉGEIÉRT TARTOZIK FELELÕSSÉGGEL! A VENDÉGEK BELÉPÉSÉRÕL A SZOBA MINDEN LAKÓJA ÉRTESÍTÉST KAP!"

    On Error Resume Next
    With OutMail
        .To = "pap.martin227@gmail.com"
        .CC = "janoki.lilla@gmail.com"
        .BCC = ""
        .Subject = "vendég belépés"
        .Body = strbody
        'You can add a file like this
        '.Attachments.Add ("C:\test.txt")
        .Send   'or use .Display
    End With
    On Error GoTo 0

    Set OutMail = Nothing
    Set OutApp = Nothing
End Sub





