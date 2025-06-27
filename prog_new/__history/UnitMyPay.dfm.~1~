object FormMyPay: TFormMyPay
  Left = 0
  Top = 0
  Caption = #1030#1089#1090#1086#1088#1110#1103' '#1074#1080#1087#1083#1072#1090
  ClientHeight = 387
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 40
    Top = 24
    Width = 181
    Height = 37
    Caption = #1030#1089#1090#1086#1088#1110#1103' '#1074#1080#1087#1083#1072#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGridPay: TDBGrid
    Left = 40
    Top = 80
    Width = 545
    Height = 217
    DataSource = DataSourcePay
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object ADOConnectionPay: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\prog_new\practik_data_baze_format2003' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 576
    Top = 320
  end
  object ADOQueryPay: TADOQuery
    Connection = ADOConnectionPay
    Parameters = <
      item
        Name = 'UserID'
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'SELECT W.'#1050#1086#1076#1042#1080#1087#1083#1072#1090#1080', W.'#1050#1086#1076#1042#1080#1087#1072#1076#1082#1091', W.'#1044#1072#1090#1072#1042#1080#1087#1083#1072#1090#1080', W.'#1057#1091#1084#1072#1042#1080#1087#1083#1072#1090#1080' '
      'FROM [Payout] AS W '
      'JOIN [Policy] AS P ON W.'#1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091' = P.'#1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091
      'WHERE P.'#1050#1086#1076#1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072' = :UserID'
      'ORDER BY W.'#1044#1072#1090#1072#1042#1080#1087#1083#1072#1090#1080' DESC')
    Left = 528
    Top = 320
  end
  object DataSourcePay: TDataSource
    DataSet = ADOQueryPay
    Left = 480
    Top = 320
  end
end
