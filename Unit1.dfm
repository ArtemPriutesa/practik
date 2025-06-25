object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1056#1077#1075#1077#1089#1090#1088#1072#1094#1110#1103
  ClientHeight = 426
  ClientWidth = 436
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 144
    Top = 33
    Width = 124
    Height = 31
    Caption = #1056#1077#1075#1077#1089#1090#1088#1072#1094#1110#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 147
    Width = 144
    Height = 23
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1087#1086#1074#1085#1077' '#1110#1084#39#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 40
    Top = 96
    Width = 102
    Height = 23
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1083#1086#1075#1110#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 40
    Top = 195
    Width = 119
    Height = 23
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 40
    Top = 248
    Width = 140
    Height = 23
    Caption = #1055#1086#1074#1090#1086#1088#1110#1090#1100' '#1087#1072#1088#1086#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditLog: TEdit
    Left = 232
    Top = 99
    Width = 161
    Height = 23
    TabOrder = 0
  end
  object EditPIP: TEdit
    Left = 232
    Top = 150
    Width = 161
    Height = 23
    TabOrder = 1
  end
  object EditPas: TEdit
    Left = 232
    Top = 198
    Width = 161
    Height = 23
    TabOrder = 2
  end
  object EditPas2: TEdit
    Left = 232
    Top = 251
    Width = 161
    Height = 23
    TabOrder = 3
  end
  object Button1: TButton
    Left = 40
    Top = 312
    Width = 353
    Height = 33
    Caption = #1047#1072#1088#1077#1075#1077#1089#1090#1088#1091#1074#1072#1090#1080#1089#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 42
    Width = 75
    Height = 25
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103
    TabOrder = 5
    OnClick = Button2Click
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\practik_data_baze_format2003.mdb;Pers' +
      'ist Security Info=False'
    LoginPrompt = False
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 336
    Top = 368
  end
  object ADOQuery1: TADOQuery
    Connection = FormAuthorization.ADOConnection1
    Parameters = <>
    Left = 384
    Top = 368
  end
end
