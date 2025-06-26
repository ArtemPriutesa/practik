object FormMyPol: TFormMyPol
  Left = 0
  Top = 0
  Caption = #1052#1086#1111' '#1076#1086#1075#1086#1074#1086#1088#1080
  ClientHeight = 432
  ClientWidth = 729
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 524
    Top = 24
    Width = 173
    Height = 37
    Caption = #1052#1086#1111' '#1076#1086#1075#1086#1074#1086#1088#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 88
    Width = 673
    Height = 265
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #1050#1086#1076#1044#1086#1075#1086#1074#1086#1088#1091
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1050#1086#1076#1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
        Width = 98
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1058#1080#1087
        Width = 109
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1044#1072#1090#1072#1055#1086#1095#1072#1090#1082#1091
        Width = 98
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1044#1072#1090#1072#1050#1110#1085#1094#1103
        Width = 83
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1041#1072#1079#1086#1074#1072#1057#1090#1072#1074#1082#1072
        Width = 92
        Visible = True
      end
      item
        Expanded = False
        FieldName = #1057#1090#1072#1090#1091#1089#1044#1086#1075#1086#1074#1086#1088#1091
        Width = 312
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 24
    Top = 34
    Width = 81
    Height = 33
    Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103
    TabOrder = 1
    OnClick = Button1Click
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
