----יצירת טבלת לוג
create table LogTable(Code int primary key identity, 
LogType nvarchar(max), LogTime datetime, messege nvarchar(max), ExceptionMsg nvarchar(MAX))

if not exists(select * from [dbo].[LogTable])
begin
create table LogTable(Code int primary key identity, 
LogType nvarchar(max), LogTime datetime, messege nvarchar(max), ExceptionMsg nvarchar(MAX))
end


drop table LogTable


select * from LogTable


IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'LogTable' AND schema_name(schema_id) = 'dbo') 
BEGIN
    CREATE TABLE dbo.LogTable(Code int primary key identity, 
    LogType nvarchar(max), LogTime datetime, messege nvarchar(max), ExceptionMsg nvarchar(MAX))
END



--bit (not typically used as a unit of storage)
--byte (1 byte)
--kilobyte (1024 bytes)
--megabyte (1024 kilobytes, or 1,048,576 bytes)
--gigabyte (1024 megabytes, or 1,073,741,824 bytes)
--terabyte (1024 gigabytes, or 1,099,511,627,776 bytes)