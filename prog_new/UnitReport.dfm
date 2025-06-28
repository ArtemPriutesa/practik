object FormReport: TFormReport
  Left = 597
  Top = 262
  Caption = #1047#1074#1110#1090
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Label1: TLabel
    Left = 170
    Top = 40
    Width = 292
    Height = 41
    Caption = #1047#1074#1110#1090' '#1087#1088#1086' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -30
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 42
    Top = 184
    Width = 282
    Height = 28
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1087#1086#1074#1085#1077' '#1110#1084#1103' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditSearchPIP: TEdit
    Left = 384
    Top = 184
    Width = 185
    Height = 23
    TabOrder = 0
  end
  object ButtonReportClick: TButton
    Left = 224
    Top = 312
    Width = 177
    Height = 41
    Caption = #1057#1090#1074#1086#1088#1080#1090#1080' '#1079#1074#1110#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonReportClickClick
  end
  object Button1: TButton
    Left = 72
    Top = 368
    Width = 75
    Height = 25
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103
    TabOrder = 2
    OnClick = Button1Click
  end
  object ADOConnectionReport: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\prog_new\practik_data_baze_format2003' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 568
    Top = 360
  end
  object ADOQuerySearch: TADOQuery
    Connection = ADOConnectionReport
    Parameters = <>
    Left = 512
    Top = 360
  end
end
