using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProjectTemplate.Model;

namespace ProjectTemplate.Entities
{
    public class MyQueue
    {
        
        private Queue<Item> myQueue = new Queue<Item>();
 //       private Queue<int> myQueue2 = new Queue<int>();
 //       private Queue<bool> myQueue3 = new Queue<bool>();
        public Item Pop()
        {
            
            if (myQueue.Count == 0) return null;
            else
                return myQueue.Dequeue();
        }
        public void Push(Item newItem)
        {
           myQueue.Enqueue(newItem);
        }
    }
}
