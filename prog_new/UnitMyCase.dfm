object FormMyCase: TFormMyCase
  Left = 0
  Top = 0
  Caption = #1052#1086#1111' '#1089#1090#1088#1072#1093#1086#1074#1110' '#1074#1080#1087#1072#1076#1082#1080
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 208
    Top = 8
    Width = 199
    Height = 28
    Caption = #1052#1086#1111' '#1089#1090#1088#1072#1093#1086#1074#1110' '#1074#1080#1087#1072#1076#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DBGridCases: TDBGrid
    Left = 16
    Top = 42
    Width = 585
    Height = 225
    DataSource = DataSourceMyCases
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1050#1086#1076#1042#1080#1087#1072#1076#1082#1091
        Width = 40
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091
        Width = 40
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1044#1072#1090#1072#1042#1080#1087#1072#1076#1082#1091
        Width = 86
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1054#1087#1080#1089
        Width = 272
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1057#1090#1072#1090#1091#1089#1042#1080#1087#1072#1076#1082#1091
        Width = 125
        Visible = True
      end>
  end
  object ButtonNewCase: TButton
    Left = 448
    Top = 304
    Width = 153
    Height = 65
    Caption = #1055#1086#1076#1072#1090#1080' '#13#10#1089#1090#1088#1072#1093#1086#1074#1080#1081' '#1074#1080#1087#1072#1076#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ButtonClose: TButton
    Left = 16
    Top = 392
    Width = 137
    Height = 34
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1100
    TabOrder = 2
    OnClick = ButtonCloseClick
  end
  object ADOConnectionMyCases: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\ARTEM\OneD' +
      'rive\Desktop\repoz\practik\prog_new\practik_data_baze_format2003' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 560
    Top = 392
  end
  object ADOQueryMyCases: TADOQuery
    Active = True
    Connection = ADOConnectionMyCases
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
      
        'SELECT C.'#1050#1086#1076#1042#1080#1087#1072#1076#1082#1091', C.'#1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091', C.'#1044#1072#1090#1072#1042#1080#1087#1072#1076#1082#1091', C.'#1054#1087#1080#1089', C.'#1057#1090#1072 +
        #1090#1091#1089#1042#1080#1087#1072#1076#1082#1091' '
      'FROM [Case] AS C '
      'INNER JOIN [Policy] AS P ON C.'#1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091' = P.'#1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091' '
      'WHERE P.'#1050#1086#1076#1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072' = :UserID')
    Left = 520
    Top = 392
  end
  object DataSourceMyCases: TDataSource
    DataSet = ADOQueryMyCases
    Left = 472
    Top = 392
  end
end
