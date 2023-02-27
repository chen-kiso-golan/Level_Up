using ProjectStudent.Model;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace ProjectStudent.Entities
{
    public class EStudents
    {
        private MStudent[] list = new MStudent[10];

        public void AddNewStudent(string name, int age ,string adress, int id)
        {
            //MStudent newStudent = new MStudent();
            //newStudent.Name = name;
            //newStudent.Age = age;

            MStudent newMStudent = new MStudent() { Age = age, Name = name, Address = adress, Id=id };

            MainManager.Instance.hashtableStudent.Add(newMStudent.Id, newMStudent);
        }


        void func4(SqlDataReader reader)
        {
            // sdfsdf

        }
        void funcRead(SqlDataReader reader)
        {
            while (reader.Read())
            {
                string Age = reader.GetString(reader.GetOrdinal("Age"));
                string Name = reader.GetString(reader.GetOrdinal("Name"));
                string Address = reader.GetString(reader.GetOrdinal("Address"));
                string Id = reader.GetString(reader.GetOrdinal("Id"));
            }
        }

        public int CalcMilga(string name, int age, string address, int id)
        {
            try
            { 
                DAL.SqlQuery.RunCommand("insert into [dbo].[StudentInfo]([Age],[Name],[Adress],[Id]) values"+"("+ age +",'"+ name + "','"+ address + "'," + id +")", funcRead);
            }
            catch (Exception)
            {

            }
            return 0;
        }


        public object BuildStudentList(SqlDataReader reader)
        {
            object ret = null;
            while (reader.Read())
            {
                MStudent student = new MStudent();
                student.Age = reader.GetInt16(reader.GetOrdinal("Age"));
                student.Address = reader.GetString(reader.GetOrdinal("Address"));
                student.Name = reader.GetString(reader.GetOrdinal("Name"));
                student.Id = reader.GetInt32(reader.GetOrdinal("Id"));
                MainManager.Instance.hashtableStudent.Add(student.Id, student);
            }

            ret = MainManager.Instance.hashtableStudent;
            return ret;
        }

        public int InsertDB_ToHash()
        {
            try
            {
              DAL.SqlQuery.RunCommandResult("select * from [dbo].[StudentInfo]", BuildStudentList);
            }
            catch (Exception)
            {

            }
            return 0;
        }

    }
}


