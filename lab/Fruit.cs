using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace labCsharp
{
    class Fruit
    {
        protected float weight;
        protected string colour;
        protected string flavor;
        protected bool edibility;

        public float WEIGHT { get; set; }
        public string COLUR { get; set; }
        public string FLAVOR { get; set; }
        public bool EDIBILITY { get; set; }

        public string squeeze()
        {
            return "The juice of the fruit";
        }

        protected static int count = 0;

        public static int getCount()
        {
            return count;
        }

        public Fruit()
        {
            weight = 0;
            colour = "unknown";
            flavor = "unknown";
            edibility = true;
            count++;
        }
        
        public Fruit(Fruit fruit)
        {
            weight = fruit.WEIGHT;
            colour = fruit.COLUR;
            flavor = fruit.FLAVOR;
            edibility = fruit.EDIBILITY;
            count++;
        }
        
        ~Fruit()
        {
            count--;
        }
    }
}
