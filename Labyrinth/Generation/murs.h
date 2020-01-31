#include<stdio.h>

class murs{
      private:
          bool present;
          char cote;
          int n;
      public:
          murs();
          bool presence();
          void cacher();
          void set_cote(char);
          void set_num(int);
          int get_num();
      };
