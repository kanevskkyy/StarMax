object DataModule1: TDataModule1
  Height = 486
  Width = 802
  PixelsPerInch = 120
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\'#1055#1088#1086#1077#1082#1090'\Win32\Deb' +
      'ug\'#1054#1085#1086#1074#1083#1077#1085#1072' '#1073#1072#1079#1072' '#1076#1072#1085#1080#1093'.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 40
    Top = 136
  end
  object ADOTCustomers: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Customers'
    Left = 160
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = ADOTCustomers
    Left = 280
    Top = 136
  end
end
