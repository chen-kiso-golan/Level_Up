using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using ProjectTemplate.DAL;
namespace ProjectTemplate.Entities
{
    public class Teachers
    {
        public void  TeacherReportedWel(SqlDataReader reader)
        {
            // action finished
        }


        public void ReportGrade(int studentId,int subjectId, int score)
        {
            string sql = $"insert into Grades(studentId,subjectId,score) values({studentId},{subjectId},{score})";

            // connect to SQL
            SqlQuery.RunCommand(sql, TeacherReportedWel);


        }
    }
}
