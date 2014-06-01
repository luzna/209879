using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace labCsharp
{
    class Apple : Fruit
    {
        private string cultivar;
        private bool ifWormy;

        public string CULTIVAR { get; set; }
        public bool IFWORMY { get; set; }

        public Apple() : base()
        {
            cultivar = "unknown";
            ifWormy = false;
            count++;
        }
        
        public Apple(Apple apple) : base(apple)
        {
            cultivar = apple.CULTIVAR;
            ifWormy = apple.IFWORMY;
            count++;
        }
        
        ~Apple()
        {
            count--;
        }
    }
}
