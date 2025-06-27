object FormCasesAdmin: TFormCasesAdmin
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1086#1076#1072#1085#1110' '#1074#1080#1087#1072#1076#1082#1080
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 46
    Top = 307
    Width = 220
    Height = 31
    Caption = #1057#1090#1072#1090#1091#1089' '#1074#1080#1088#1072#1085#1086#1111' '#1079#1072#1103#1074#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 46
    Top = 29
    Width = 177
    Height = 37
    Caption = #1055#1086#1076#1072#1085#1110' '#1079#1072#1103#1074#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 46
    Top = 124
    Width = 537
    Height = 149
    DataSource = DataSource1
    Options = [dgEditing, dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
  end
  object ComboBoxStatus: TComboBox
    Left = 288
    Top = 311
    Width = 121
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ButtonApply: TButton
    Left = 422
    Top = 311
    Width = 161
    Height = 31
    Caption = #1047#1084#1110#1085#1080#1090#1080' '#1089#1090#1072#1090#1091#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonApplyClick
  end
  object Button1: TButton
    Left = 46
    Top = 86
    Width = 75
    Height = 25
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1100
    TabOrder = 3
    OnClick = Button1Click
  end
  object ADOQueryCases: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    Left = 512
    Top = 368
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\prog_new\practik_data_baze_format2003' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 560
    Top = 368
  end
  object DataSource1: TDataSource
    DataSet = ADOQueryCases
    Left = 464
    Top = 368
  end
  object ADOQueryPay: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 416
    Top = 368
  end
end
