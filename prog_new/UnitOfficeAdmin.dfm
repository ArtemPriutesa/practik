object FormOfficeAdmin: TFormOfficeAdmin
  Left = 581
  Top = 295
  Caption = #1054#1092#1110#1089' '#1072#1076#1084#1110#1085#1072
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 230
    Top = 32
    Width = 339
    Height = 31
    Caption = #1051#1072#1089#1082#1072#1074#1086' '#1087#1088#1086#1089#1080#1084#1086' '#1072#1076#1084#1110#1085#1110#1089#1090#1088#1072#1090#1086#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 40
    Top = 72
    Width = 153
    Height = 281
    TabOrder = 0
    object Button1: TButton
      Left = 13
      Top = 24
      Width = 129
      Height = 41
      Caption = #1055#1088#1086#1092#1110#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 13
      Top = 88
      Width = 129
      Height = 41
      Caption = #1055#1077#1088#1077#1075#1083#1103#1085#1091#1090#1080' '#13#10#1087#1086#1076#1072#1085#1110' '#1074#1080#1087#1072#1076#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button3Click
    end
    object Button2: TButton
      Left = 13
      Top = 152
      Width = 129
      Height = 41
      Caption = #1047#1074#1110#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
    object Button4: TButton
      Left = 13
      Top = 216
      Width = 129
      Height = 41
      Caption = #1042#1080#1093#1110#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button4Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 576
    Top = 368
    object N1: TMenuItem
      Caption = #1053#1072#1083#1072#1096#1090#1091#1074#1072#1085#1085#1103
      OnClick = N1Click
    end
  end
end
