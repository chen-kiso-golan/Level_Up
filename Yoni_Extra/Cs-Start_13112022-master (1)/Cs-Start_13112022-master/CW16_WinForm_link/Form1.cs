using System;
using System.Diagnostics;
using System.Xml;
using static System.Net.Mime.MediaTypeNames;

namespace CW16_WinForm_link
{
    public partial class Form1 : Form
    {
        int count = 0;
        public Form1()
        {
            InitializeComponent();
        }

        void func1()
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < int.MaxValue; i++)
                {

                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text = "start";

            Task t = Task.Run(func1);
            int f = 90;

            Task.Run(() =>
            {
                f++;
                for (int i = 0; i < 10; i++)
                {
                    //label1.Text = $"{i}";
                    count++;
                    Thread.Sleep(1000);
                }
            });
            int g = 9;       
        }


        public Task<string> GoToInternet()
        {
            return Task.Run(() =>
            {
                Thread.Sleep(2000);
                return "ResultInternert";
            });
        }

        public Task<int> GoToInternet2()
        {
            return Task.Run(() =>
            {
                Thread.Sleep(1000);
                return 2;
            });
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            var t = await GoToInternet();
            label1.Text = t;

            var y = await GoToInternet2();
            label2.Text = y.ToString();
        }

        private async void WriteToFileBtn_Click(object sender, EventArgs e)
        {
            await CreateAndWriteToFile();
        }

        public Task CreateAndWriteToFile()
        {
            return Task.Run(() =>
            {
                if (!File.Exists("fileExample.txt"))
                {
                    using (File.Create("fileExample.txt"))
                    {
                        MessageBox.Show("File created successfully.");

                    }
                   
                    using (StreamWriter sw = new StreamWriter("fileExample.txt", true))
                    {
                        for (int i = 0; i<10; i++)
                        {
                            sw.WriteLine(i.ToString());
                        }
                        MessageBox.Show("Wrote in File successfully.");
                    }
                    
                }
                else
                {
                    using (StreamWriter sw = new StreamWriter("fileExample.txt", true))
                    {
                        for (int i = 0; i < 10; i++)
                        {
                            sw.WriteLine(i.ToString());
                        }
                        MessageBox.Show("Wrote in File successfully.");
                    }
                }
            });
        }

        int num = 11;
        public Task<int> CountDown()
        {

            return Task.Run(() =>
            {
                num--;
                Thread.Sleep(1000);
                return num;

            });
           
        }

        private async void CountDownBtn_Click(object sender, EventArgs e)
        {
            for (int i = 0; i <= 10; i++)
            {
                var t = await CountDown();
                label3.Text = t.ToString();
            }
            num = 11;
        }

        public Task<string> WebDataString() 
        {
            return Task.Run(() =>
            {
                Thread.Sleep(2000);
                System.Net.WebClient wc = new System.Net.WebClient();
                //string webData = wc.DownloadString("https://www.ynet.co.il/home/0,7340,L-8,00.html");
                string webData = wc.DownloadString(" https://www.ynet.co.il/Integration/StoryRss2.xml");
                return webData;
            });
        }

      
        private async void webDataBtn_Click(object sender, EventArgs e)
        {
            webDataBtn.Enabled = false;

            var stopwatch = new Stopwatch();
            stopwatch.Start();

            for (int i = 0; i < int.MaxValue; i++)  
            {
                while (stopwatch.Elapsed < TimeSpan.FromSeconds(10))
                {
                    var t = await WebDataString();
                    webText.Text = t.ToString();
                    label4.Text = "the size is: " + t.Length.ToString() + " bytes";
                }
                break;
            }

            webDataBtn.Enabled = true;
        }

        private void webText_TextChanged(object sender, EventArgs e)
        {

        }

        async Task<string> YnetTitlesPage()
        {
            string result;
            using (var client = new HttpClient())
            {
                var webData = await client.GetStringAsync("http://www.ynet.co.il/Integration/StoryRss2.xml");
                var doc = new XmlDocument();
                doc.LoadXml(webData);

                var titles = new List<string>();
                var items = doc.GetElementsByTagName("item");
                foreach (XmlNode item in items)
                {
                    var titleNode = item.SelectSingleNode("title");
                    var pubDateNode = item.SelectSingleNode("pubDate");
                    titles.Add($"[{pubDateNode.InnerText.Replace(" +0200","")}]\r\n~{titleNode.InnerText}~");
                }
                result = string.Join("\r\n", titles);
            }
            return result;
        }

        private async void YnetTitelBtn_Click(object sender, EventArgs e)
        {
            YnetTitelBtn.Enabled = false;

            var stopwatch = new Stopwatch();
            stopwatch.Start();

            for (int i = 0; i < int.MaxValue; i++)
            {
                while (stopwatch.Elapsed < TimeSpan.FromSeconds(10))
                {
                    var t = await Task.Run(YnetTitlesPage);
                    webText.Text =$"the time Now: {DateTime.Now}\r\n {t}";
                    label4.Text = "the size is: " + t.Length.ToString() + " bytes";
                }
                break;
            }

            YnetTitelBtn.Enabled = true;
        }
    }
}