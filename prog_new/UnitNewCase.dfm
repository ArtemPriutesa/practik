object FormNewCase: TFormNewCase
  Left = 629
  Top = 229
  Caption = #1055#1086#1076#1072#1090#1080' '#1089#1090#1088#1072#1093#1086#1074#1080#1081' '#1074#1080#1087#1072#1076#1086#1082
  ClientHeight = 442
  ClientWidth = 615
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 56
    Top = 40
    Width = 336
    Height = 37
    Caption = #1055#1086#1076#1072#1090#1080' '#1089#1090#1088#1072#1093#1086#1074#1080#1081' '#1074#1080#1087#1072#1076#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 56
    Top = 112
    Width = 194
    Height = 28
    Caption = #1042#1082#1072#1078#1110#1090#1100' '#1076#1072#1090#1091' '#1074#1080#1087#1072#1076#1082#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 56
    Top = 261
    Width = 241
    Height = 28
    Caption = #1050#1086#1088#1086#1090#1082#1086' '#1086#1087#1080#1096#1110#1090#1100' '#1074#1080#1087#1072#1076#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 56
    Top = 168
    Width = 252
    Height = 56
    Caption = #1042#1082#1072#1078#1110#1090#1100' '#1076#1086' '#1103#1082#1086#1075#1086' '#1076#1086#1075#1086#1074#1086#1088#1091' '#13#10#1087#1088#1080#1087#1080#1089#1072#1090#1080' '#1094#1077#1081' '#1074#1080#1087#1072#1076#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DateTimePickerCase: TDateTimePicker
    Left = 375
    Top = 117
    Width = 186
    Height = 23
    Date = 45834.000000000000000000
    Time = 0.586705972222262000
    TabOrder = 0
  end
  object EditDescription: TEdit
    Left = 375
    Top = 261
    Width = 185
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 408
    Top = 332
    Width = 121
    Height = 45
    Caption = #1057#1090#1074#1086#1088#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 334
    Width = 129
    Height = 45
    Cancel = True
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object ComboBoxPol: TComboBox
    Left = 376
    Top = 184
    Width = 185
    Height = 23
    TabOrder = 4
  end
  object ADOConnectionNewCase: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\prog_new\practik_data_baze_format2003' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 568
    Top = 400
  end
  object ADOQueryNewCase: TADOQuery
    Connection = ADOConnectionNewCase
    Parameters = <>
    Left = 520
    Top = 400
  end
  object ADOQueryPol: TADOQuery
    Connection = ADOConnectionNewCase
    Parameters = <>
    Left = 472
    Top = 400
  end
end
