object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 749
  ClientWidth = 1355
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 1353
    Height = 752
  end
  object Image2: TImage
    Left = 8
    Top = 16
    Width = 66
    Height = 33
    OnClick = Image2Click
  end
  object Button1: TButton
    Left = 112
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Cartones'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 208
    Top = 26
    Width = 57
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object SGB: TStringGrid
    Left = 488
    Top = 32
    Width = 697
    Height = 57
    ColCount = 1
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 2
  end
  object Button2: TButton
    Left = 304
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Bolo'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 416
    Top = 24
  end
end
