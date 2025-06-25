object FormMyPolicies: TFormMyPolicies
  Left = 0
  Top = 0
  Caption = #1052#1086#1111' '#1076#1086#1075#1086#1074#1086#1088#1080
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object DBGridMyPolicies: TDBGrid
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    Align = alClient
    DataSource = DataSourceMyPolicies
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object ADOConnectionMyPolicies: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\practik_data_baze_format2003.mdb;Pers' +
      'ist Security Info=False;'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 568
    Top = 376
  end
  object ADOQueryMyPolicies: TADOQuery
    Active = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\practik_data_baze_format2003.mdb;Pers' +
      'ist Security Info=False'
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'UserID'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM [Policy] WHERE '#1050#1086#1076#1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072' = :UserID')
    Left = 520
    Top = 376
  end
  object DataSourceMyPolicies: TDataSource
    DataSet = ADOQueryMyPolicies
    Left = 472
    Top = 376
  end
end
