using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectB.Entities.command
{
    public interface ICommand
    {
        object Execute(params object[] param);
    }
}
