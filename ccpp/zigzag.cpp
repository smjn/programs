string convert(string s, int numRows) {

        if(!s.size())   return "";

        if(numRows==1) return s;

        

        string *vs=new string[numRows];

        

        bool d=true;

        int rindex=0;

        

        for(int i=0;i<s.size();i++){

            if(d){

                vs[rindex]+=s[i];

                if(rindex==numRows-1){

                    d=false;

                }else{

                    rindex++;

                }

            } else{

                rindex--;

                if(!rindex){

                    d=true;

                    i--;

                } else{

                    vs[rindex]+=s[i]; 

                }

            }

        }

        string res;

        for(int i=0;i<numRows;i++){

            res+=vs[i];

        }

        return res;

    }
