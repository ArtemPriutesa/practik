object FormMyPol: TFormMyPol
  Left = 0
  Top = 0
  Caption = #1052#1086#1111' '#1076#1086#1075#1086#1074#1086#1088#1080
  ClientHeight = 441
  ClientWidth = 674
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 8
    Top = 32
    Width = 658
    Height = 201
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
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
    Left = 120
    Top = 384
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
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
      'SELECT * FROM [Policy] WHERE '#1050#1086#1076#1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072' = :UserID'
      '')
    Left = 64
    Top = 384
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 8
    Top = 384
  end
end
