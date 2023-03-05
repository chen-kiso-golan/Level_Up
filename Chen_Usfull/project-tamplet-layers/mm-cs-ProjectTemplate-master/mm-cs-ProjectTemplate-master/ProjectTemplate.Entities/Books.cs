using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectTemplate.Entities
{
    public class Books
    {
        private System.Collections.ArrayList BookList = new System.Collections.ArrayList();
        public void AddBook()
        {
            Model.Book book1 = new Model.Book() { Id = 12, Name = "Harry Poter" };
            Model.Book book2 = new Model.Book() { Id = 12, Name = "Harry Poter" };
            Model.Book book3 = new Model.Book() { Id = 12, Name = "Harry Poter" };

            BookList.Add(book1);
            BookList.Add(book2);
            BookList.Add(book3);


        }
    }
}
