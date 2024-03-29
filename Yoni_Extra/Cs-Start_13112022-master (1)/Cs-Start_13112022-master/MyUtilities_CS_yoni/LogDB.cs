﻿using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyUtilities_CS_yoni
{
    public class LogDB : ILogger
    {
        public static string ConnectionString = @"Integrated Security=SSPI;   Persist Security Info=False;    Initial Catalog=Log;  Data Source=localhost\sqlexpress";

        string LogTableName = "LogTable";
        public void Init()
        {
            SqlQuery.ConnectionStringInit(ConnectionString);
            string CreateTableQuery = "IF NOT EXISTS (SELECT * FROM sys.tables WHERE name = 'LogTable' AND schema_name(schema_id) = 'dbo') \r\nBEGIN\r\n    CREATE TABLE dbo.LogTable(Code int primary key identity, \r\n    LogType nvarchar(max), LogTime datetime, messege nvarchar(max), ExceptionMsg nvarchar(MAX))\r\nEND";
            SqlQuery.WriteToDB(CreateTableQuery);
            LogCheckHouseKeeping();
        }

        public void LogEvent(string message)
        {
            string sqlQuery = $"insert into {LogTableName} values('Event', getdate(),'{message}',null)";
            SqlQuery.WriteToDB(sqlQuery);
        }
        public void LogError(string message)
        {
            string sqlQuery = $"insert into {LogTableName} values('Error', getdate(),'{message}',null)";
            SqlQuery.WriteToDB(sqlQuery);
        }

        public void LogException(string message, Exception ex)
        {
            string sqlQuery = $"insert into {LogTableName} values('Exception', getdate(),'{message}', '{ex.Message}')";
            SqlQuery.WriteToDB(sqlQuery);
        }

        public void LogCheckHouseKeeping()
        {
            string sqlQuery = $"DELETE FROM {LogTableName}\r\nWHERE Date < DATEADD(month, -3, GETDATE());";
            SqlQuery.WriteToDB(sqlQuery);
        }
    }
}
