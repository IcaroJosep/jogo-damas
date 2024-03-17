#include  <iostream>
#include  <vector>

using namespace std;
char vazio='0';
char adversario;
bool andarPtras=false;
static int la,b,lc,d,le,f,lg,h;
static bool fimdjogo=false;


void ordemdejogo(vector<vector<char>>& matriz, int l, int c, int ldes, int cdes, char p);
void ImpTabulero(vector<vector<char>>&matriz);
void jogada(vector<vector<char>>&matriz);
void testeposicao(int& la,int& b ,int& lc,int& d,int& le,int& f ,int& lg,int& h,int& l,int& c);
void fimDjogo(vector<vector<char>>&matriz);


void fimDjogo(vector<vector<char>>&matriz){

    static int x;
    static int m;
    x=0;
    m=0;
       for (vector<vector<char>>::iterator linha_it = matriz.begin(); linha_it != matriz.end(); ++linha_it) {
        for (vector<char>::iterator coluna_it = linha_it->begin(); coluna_it != linha_it->end(); ++coluna_it) {
             if(*coluna_it=='x'){
                x++;
             }else if(*coluna_it=='m'){
                m++;
             }
         }

      }

      if(m==0||x==0){
         cout << "fim do jogo"<<endl;
          if(m==0){
            cout<<"  X  foi o ganhado"<<endl;
          }else{cout<<"  M   foi o ganhador"<<endl; }
          fimdjogo=true;
      }else{
          jogada(matriz);
      }

}


void testeposicao(int& la,int& b ,int& lc,int& d,int& le,int& f ,int& lg,int& h,int& l,int& c){
   la=l+1;  b=c-1;
   lc=l+1;  d=c+1;
   le=l-1;  f=c-1;
   lg=l-1;  h=c+1;
   /*(matriz[l+1][c-1]
     (matriz[l+1][c+1]
     (matriz[l-1][c-1]
     (matriz[l-1][c+1] {*/

   if(l==7){
     la=l;
     lc=l;
   }else if(l==0){
     le=l;
     lg=l;
   }

   if(c==7){
     b=c;
     d=c;
   }else if(c==0){
     f=c;
     h=c;
   }
}


void ImpTabulero(vector<vector<char>>&matriz){
  int linha=matriz.size();
  int coluna=matriz[0].size();

           cout<<"L 0 1 2 3 4 5"<<endl;
           for(int l=0;l<linha;l++){
             cout<<l;
               for(int c=0;c<coluna;c++){
               cout<<"|"<<matriz[l][c];
               }
             cout<<endl;

           }
           cout<<"C";
cout<<"--|--|--|"<<endl;
}


void jogada(vector<vector<char>>&matriz){
  int l;
  int c;
  char p;
  int ldes;
  int cdes;




            do {
            cout<<"linha :";
            cin>>l;
            cout<<"coluna :";
            cin>>c;
            p=matriz[l][c];
             if(p!='x'&&p!='m'){
              cout<<"selecao invalida !!!!!"<<endl;
              }
            }while(p!='x'&&p!='m');

        if(p=='x'){
          adversario='m';
        }else{
          adversario='x';
        }

            do {
            cout<<"destino"<<endl;
            cout<<"linha destino :";
            cin>>ldes;
            cout<<"coluna destino :";
            cin>>cdes;
            }while((ldes!=l+1&&ldes!=l-1)||(cdes!=c+1&&cdes!=c-1));


       ordemdejogo(matriz,l ,c,ldes,cdes, p);
}

void ordemdejogo(vector<vector<char>>&matriz,int l ,int c,int ldes,int cdes,char p){
//           cout<<"\nentrada\n";
           if(matriz[ldes][cdes]==vazio){
//cout<<"..mep 1"<<endl;
             if(p=='x'){
//    cout<<"..mep 1.1"<<endl;
                 if(ldes<l){
//       cout<<"..mep 1.1/1"<<endl;
                    cout<<"\njogada invalida\n";
                    cout<<"\ntente de novo\n";
                    jogada(matriz);
                 }else{
//       cout<<"..mep 1.1/2"<<endl;
                    matriz[ldes][cdes]=p;
                    matriz[l][c]=vazio;
                 }
             }else if(p=='m'){
//    cout<<"..mep 1.2"<<endl;
                  if(ldes>l){
//        cout<<"..mep 1.2/1"<<endl;
                    cout<<"\njogada invalida\n";
                    cout<<"\ntente de novo\n";
                    jogada(matriz);
                  }else{
//        cout<<"..MEP 1.2/2"<<endl;
                    matriz[ldes][cdes]=p;
                    matriz[l][c]=vazio;
                  }
            }
           }else if(matriz[ldes][cdes]!=vazio){
//cout<<"..mep 2"<<endl;
                    if(cdes>c){
//    cout<<"..mep 2.1"<<endl;
                       if (ldes<l){
//       cout<<"..mep 2.1.1  /1"<<endl;
                        andarPtras=true;
                        ldes--;
                       }else{
//       cout<<"..mep 2.1.1  /2"<<endl;
                        ldes++;
                       }
                        cdes++;
                         ImpTabulero(matriz);
                         if(matriz[ldes][cdes]==vazio){
//       cout<<"..mep 2.1.2"<<endl;
                            if(andarPtras==true){
//            cout<<"..mep 2.1.2.1  /1"<<endl;
                            matriz[ldes][cdes]=p;
                            matriz[l][c]=vazio;
                            matriz[ldes+1][cdes-1]=vazio;
                                  l=ldes;
                                  c=cdes;
                             andarPtras=false;
                            }else{
//            cout<<"..mep 2.1.2.1  /2"<<endl;
                            matriz[ldes][cdes]=p;
                            matriz[l][c]=vazio;
                            matriz[ldes-1][cdes-1]=vazio;
                                  l=ldes;
                                  c=cdes;

                            }

                                   testeposicao( la, b , lc, d,le, f , lg, h, l, c);



                                   ImpTabulero(matriz);
                                     if ((matriz[la][b] == adversario ) ||
                                         (matriz[lc][d] == adversario ) ||
                                         (matriz[le][f] == adversario ) ||
                                         (matriz[lg][h] == adversario )) {
//            cout<<"..mep 2.1.2.2  comsecutiva"<<endl;
                                         static bool jogadaValida;
                                          jogadaValida=false;
                                         do{
//                  cout<<"..mep 2.1.2.2.1 "<<endl;
                                            cout<<"\ntu pode fz mas uma jogada \n";
                                            cout<<"deseja faze-la \n1 = sim \n2 = nao\n"<<endl;
                                              int fz=0;
                                               cin>>fz;
                                               if(fz==1){
//                        cout<<"..mep 2.1.2.2.1.1 "<<endl;
                                                 cout<<"\njoge\n";
                                                    cout<<"destino"<<endl;
                                                    cout<<"linha destino :";
                                                    cin>>ldes;
                                                    cout<<"coluna destino :";
                                                    cin>>cdes;


                                                    if(ldes<l){
//                             cout<<"..mep 2.1.2.2.1.1.1 "<<endl;
                                                        if(matriz[ldes][cdes]==adversario){
//                                    cout<<"..mep 2.1.2.2.1.1.1.1 "<<endl;
                                                           ordemdejogo(matriz,l ,c,ldes,cdes, p);
                                                          cout<<"tamuleiro 2"<<endl;
                                                           ImpTabulero(matriz);

                                                        }else{
//                                    cout<<"..mep 2.1.2.2.1.1.1.2 "<<endl;
                                                          cout<<"jogada invalioda;\n";
                                                        }
                                                    }else if(ldes>l){
//                             cout<<"..mep 2.1.2.2.1.1.2 "<<endl;
                                                        ordemdejogo(matriz,l ,c,ldes,cdes, p);
                                                         jogadaValida=true;
                                                    }else{
//                             cout<<"..mep 2.1.2.2.1.1.3 "<<endl;
                                                        cout<<"\njogada invalida"<<endl;
                                                    }
                                                   jogadaValida=true;
                                               }else if(fz==2){
//                        cout<<"..mep 2.1.2.2.1.2 "<<endl;
                                                 cout<<"\nfim da sua vez\n";
                                                 jogadaValida=true;
                                               }else{
//                        cout<<"..mep 2.1.2.2.1.3 "<<endl;
                                                 cout<<"\ntente de novo\n";
                                               }
                                            }while(jogadaValida!=true);

                            }else{
//            cout<<"..mep 2.1.2.3  comsecutiva nefgada"<<endl;
                                cout<<"fim da sua vez !!\n";
                            }
                    }else{
//       cout<<"..mep 2.1.3 "<<endl;
                        cout<<"jogada invalida"<<endl;
                    }
          }else if(cdes<c){////aquiiiii
//     cout<<"..mep 2.2"<<endl;
                      if (ldes<l){
//         cout<<"..mep 2.2.1  /1"<<endl;
                        andarPtras=true;
                        ldes--;
                       }else{
//         cout<<"..mep 2.2.1  /2"<<endl;
                        ldes++;
                       }
                        cdes--;
                        if(matriz[ldes][cdes]==vazio){
//      cout<<"..mep 2.2.2"<<endl;
                            if(andarPtras==true){
//            cout<<"..mep 2.2.2.1  /1"<<endl;
                            matriz[ldes][cdes]=p;
                            matriz[l][c]=vazio;
                            cout<<ldes<<cdes<<endl;
                            matriz[ldes+1][cdes+1]=vazio;
                                  l=ldes;
                                  c=cdes;
                             andarPtras=false;
                            }else{
//            cout<<"..mep 2.2.2.1  /2"<<endl;
                            matriz[ldes][cdes]=p;
                            matriz[l][c]=vazio;
                            matriz[ldes-1][cdes+1]=vazio;
                                 cout<<ldes<<cdes<<endl;
                                  l=ldes;
                                  c=cdes;

                            }
                                ImpTabulero(matriz);

                                   testeposicao( la, b , lc, d,le, f , lg, h, l, c);



                                   ImpTabulero(matriz);
                                     if ((matriz[la][b] == adversario ) ||
                                         (matriz[lc][d] == adversario ) ||
                                         (matriz[le][f] == adversario ) ||
                                         (matriz[lg][h] == adversario )) {
//            cout<<"..mep 2.2.2.2  comsecutiva"<<endl;
                                         static bool jogadaValida;
                                          jogadaValida=false;
                                         do{
//                  cout<<"..mep 2.2.2.2.1 "<<endl;
                                            cout<<"\ntu pode fz mas uma jogada \n";
                                            cout<<"deseja faze-la \n1 = sim \n2 = nao\n"<<endl;
                                              int fz=0;
                                               cin>>fz;
                                               if(fz==1){
//                        cout<<"..mep 2.2.2.2.1.1 "<<endl;
                                                 cout<<"\njoge\n";
                                                    cout<<"destino"<<endl;
                                                    cout<<"linha destino :";
                                                    cin>>ldes;
                                                    cout<<"coluna destino :";
                                                    cin>>cdes;


                                                    if(ldes<l){
//                             cout<<"..mep 2.2.2.2.1.1.1 "<<endl;
                                                        if(matriz[ldes][cdes]==adversario){
//                                    cout<<"..mep 2.2.2.2.1.1.1.1 "<<endl;
                                                           ordemdejogo(matriz,l ,c,ldes,cdes, p);
                                                          cout<<"tamuleiro 2"<<endl;
                                                           ImpTabulero(matriz);

                                                        }else{
//                                    cout<<"..mep 2.2.2.2.1.1.1.2 "<<endl;
                                                          cout<<"jogada invalioda;\n";
                                                        }
                                                  }else if(ldes>l){
//                             cout<<"..mep 2.2.2.2.1.1.2 "<<endl;
                                                        ordemdejogo(matriz,l ,c,ldes,cdes, p);
                                                         jogadaValida=true;
                                                    }else{
//                           cout<<"..mep 2.2.2.2.1.1.3 "<<endl;
                                                        cout<<"\njogada invalida"<<endl;
                                                    }
                                                   jogadaValida=true;
                                               }else if(fz==2){
//                        cout<<"..mep 2.2.2.2.1.2 "<<endl;
                                                 cout<<"\nfim da sua vez\n";
                                                 jogadaValida=true;
                                               }else{
//                        cout<<"..mep 2.2.2.2.1.3 "<<endl;
                                                 cout<<"\ntente de novo\n";
                                               }
                                            }while(jogadaValida!=true);

                            }else{
 //           cout<<"..mep 2.2.2.3  comsecutiva nefgada"<<endl;
                                cout<<"fim da sua vez !!\n";
                            }


                        }else{
                         cout<<"\njogada invalida\n";

                        }


        }

//     cout<<"fim fim 1 e 2"<<endl;
    }
//cout<<"..mep 3 fim real"<<endl;
  cout<<"fim"<<endl;
}


int main (){
 static int linha=8,coluna=8;
  vector<vector<char>>t(linha,vector<char>(coluna,vazio));


 t[0][1]='x';
 t[0][3]='x';
 t[0][5]='x';
 t[0][7]='x';

 t[1][0]='x';
 t[1][2]='x';
 t[1][4]='x';
 t[1][6]='x';

 t[2][1]='x';
 t[2][3]='x';
 t[2][5]='x';
 t[2][7]='x';
/////////////
 t[7][0]='m';
 t[7][2]='m';
 t[7][4]='m';
 t[7][6]='m';

 t[6][1]='m';
 t[6][3]='m';
 t[6][5]='m';
 t[6][7]='m';

 t[5][0]='m';
 t[5][2]='m';
 t[5][4]='m';
 t[5][6]='m';
ImpTabulero(t);

           do{

                fimDjogo(t);
          ImpTabulero(t);
           }while(fimdjogo==false);




return 0;
}





































