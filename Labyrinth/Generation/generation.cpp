#include <vector>
#include <cstdlib>
#include<iostream>
#include "generation.h"

using namespace std;
    generation::generation(){
           lignes=10;
           cols=20;
    }
    
    int generation::get_lignes(){
           return lignes;
    }
    int generation::get_cols(){
           return cols;
    }
    void generation::generer(){
        
        vector<int> targeti;
        vector<int> targetj;
        vector<int> possibility;
        int d,g,h,b,x,num_mur_contre,num_mur;
        
        int debuti=rand()%lignes;
        int debutj=rand()%cols;
        int xi=debuti;
        int xj=debutj;
        targeti.push_back(xi);
        targetj.push_back(xj);
        
        cout<<"depart : i = "<<xi<<" j = "<<xj<<endl; 
        for(int i=0;i<lignes;i++){
                for (int j=0;j<cols;j++)
                    cout<<c[i][j].get_etat()<<" ";
                cout<<endl;
        }
        cout<<endl<<endl;
        int i = 0;
        do{  
                possibility.clear();
                c[xi][xj].visite();
                d=xj+1;
                g=xj-1;
                h=xi-1;
                b=xi+1;
                if(!c[xi][d].is_visited() && d>=0 && d<cols){ possibility.push_back(xi);possibility.push_back(d);}//cout<<"cellule["<<xi<<"]["<<d<<"]"<<" non visitée !!!"<<endl;}
                if(!c[xi][g].is_visited() && g>=0 && g<cols){ possibility.push_back(xi);possibility.push_back(g);}//cout<<"cellule["<<xi<<"]["<<g<<"]"<<" non visitée !!!"<<endl;}
                if(!c[h][xj].is_visited() && h>=0 && h<lignes){ possibility.push_back(h);possibility.push_back(xj);}//cout<<"cellule["<<h<<"]["<<xj<<"]"<<" non visitée !!!"<<endl;}
                if(!c[b][xj].is_visited() && b>=0 && b<lignes){ possibility.push_back(b);possibility.push_back(xj);}//cout<<"cellule["<<b<<"]["<<xj<<"]"<<" non visitée !!!"<<endl;}
                cout<<endl<<endl<<endl;
                
                if(possibility.size()==0){
                       i--;
                       xi=targeti[i];
                       xj=targetj[i];
                       continue;
                }
                i++;
                x=rand()%(possibility.size());
                if (x & 1) {x--;cout<<"x est impaire !!!!!!!!!!!!!!"<<endl;}
                if(possibility[x]==xi){
                     if(possibility[x+1]==d) {num_mur=3;num_mur_contre=2;}
                     else       {num_mur=2;num_mur_contre=3;}
                               
                }
                if (possibility[x+1]==xj){
                     if (possibility[x]==h) {num_mur=0;num_mur_contre=1;}
                     else      {num_mur=1;num_mur_contre=0;}
                }     
                c[xi][xj].detruire_mur(num_mur);
                xi=possibility[x];
                xj=possibility[x+1];
                c[xi][xj].detruire_mur(num_mur_contre);
                cout<<"cellule suivante  c["<<xi<<"]["<<xj<<"]"<<endl;
          
                targeti.push_back(xi);
                targetj.push_back(xj);
        }while (i!=0);
        
        for(int i=0;i<lignes;i++){
                for (int j=0;j<cols;j++)
                    cout<<c[i][j].get_etat()<<" ";
                cout<<endl;
        }
        
}

