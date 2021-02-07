object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 461
  ClientWidth = 287
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Расходимость: TLabel
    Left = 183
    Top = 5
    Width = 71
    Height = 13
    Caption = #1056#1072#1089#1093#1086#1076#1080#1084#1086#1089#1090#1100
  end
  object Label1: TLabel
    Left = 183
    Top = 78
    Width = 94
    Height = 13
    Caption = #1064#1072#1075' '#1087#1086' '#1076#1077#1090#1077#1082#1090#1086#1088#1091
  end
  object Label2: TLabel
    Left = 183
    Top = 124
    Width = 67
    Height = 13
    Caption = #1064#1072#1075' '#1087#1086' '#1089#1080#1075#1084#1077
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 169
    Height = 146
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 183
    Top = 175
    Width = 96
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo2: TMemo
    Left = 8
    Top = 160
    Width = 169
    Height = 293
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 183
    Top = 24
    Width = 96
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 183
    Top = 51
    Width = 96
    Height = 21
    TabOrder = 4
    Text = 'Edit2'
  end
  object Button2: TButton
    Left = 183
    Top = 206
    Width = 96
    Height = 25
    Caption = 'Button2'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 183
    Top = 97
    Width = 96
    Height = 21
    TabOrder = 6
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 183
    Top = 143
    Width = 96
    Height = 21
    TabOrder = 7
    Text = 'Edit4'
  end
  object ProgressBar1: TProgressBar
    Left = 183
    Top = 237
    Width = 96
    Height = 17
    TabOrder = 8
  end
end
