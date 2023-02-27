using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SocialProject.Entities
{
    public class MainManager
    {
        public AllFormsManager AllFormsManager;
        public UsersManager UsersManager;
        public TwitterManager twitterManager;
        private MainManager()
        {
            init();
        }

        public void init()
        {
            AllFormsManager = new AllFormsManager();
            UsersManager = new UsersManager();
            twitterManager = new TwitterManager();
            //lomanageg log1 = new logmanager(file);
            //log1.LogEvent(msg);

        }
        private static readonly MainManager instance = new MainManager();
        public static MainManager Instance { get { return instance; } }

    }
}
