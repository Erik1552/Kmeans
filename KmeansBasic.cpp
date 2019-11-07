

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

struct dataHolder{
    int r;
    int g;
    int b;
    int ClusterAssigned;
};

dataHolder Cluster[16] = {0,0,0,0}; // To hold cluster centers

dataHolder input[262144]; // To hold all the pixels
bool readFile(dataHolder input[], string infilex);
int distance(double r1, double g1, double b1, double r2, double g2, double b2);
void saveClusterCentersToFile(dataHolder input[]);
int repetitions = 0;
int x;
// HOLDERS FOR OLDER CLUSTERS TO COMPARE TO
dataHolder compare[16];

int main() {

     // 1. Import file with the data
    
    // Add source file
    string infile("");
    
    if(!readFile(input, infile))
      {
      cout << "ERROR: Could not read the input file" << endl;
      exit(0);
      }
    else {
        cout << "File was uploaded"<<endl;
    }
    
    // 2. Save the first 16 distinct points as centers
    
      cout << "Storing first distinct** 16 points as cluster centers"<<endl<<endl<<endl;
        int temp = 0;
        int k = 0;
        for (int j = 1; j < 200; j++){
            if (Cluster[k].r == input[j].r && Cluster[k].g == input[j].g && Cluster[k].b == input[j].b){
                j++;
            }
            else {
                Cluster[k].r = input[j].r;
                Cluster[k].g = input[j].g;
                Cluster[k].b = input[j].b;
                k++;
                temp++;
                if(temp == 16){
                    break;
                }
    }
        }
    
    // 3. Run through the program and assign the rest of the points to a center that its closest to

    // Calculate distances
    // Save correct distance to correct input pixel struct
    // go to next one
    
    //***********LOOP Start Point
    int forever = 0;
    while(forever == 0){
    
    
    int i = 0;
    while(i < 262144){
        
    int tempassign = 0;
        
     x = distance(input[i].r, input[i].g, input[i].b, Cluster[0].r, Cluster[0].g, Cluster[0].b);
    
        for (int h = 1; h < 16; h++){ //Going through the rest of the clusters
       
            if (distance(input[i].r, input[i].g, input[i].b, Cluster[h].r, Cluster[h].g, Cluster[h].b) < x){ // if distance is less then its the new distance
           
                x = distance(input[i].r, input[i].g, input[i].b, Cluster[h].r, Cluster[h].g, Cluster[h].b);
                tempassign = h;
        }
        }
        
        input[i].ClusterAssigned = tempassign;
        i++;
    
    }
    
    // 4. Update the cluster centers to the new centers that its close by
    
    
   // Creating values to perform all the calculations for each cluster
    int input0R = 0, input0B = 0, input0G = 0, cluster0total = 0;
    int input1R = 0, input1B = 0, input1G = 0, cluster1total = 0;
    int input2R = 0, input2B = 0, input2G = 0, cluster2total = 0;
    int input3R = 0, input3B = 0, input3G = 0, cluster3total = 0;
    int input4R = 0, input4B = 0, input4G = 0, cluster4total = 0;
    int input5R = 0, input5B = 0, input5G = 0, cluster5total = 0;
    int input6R = 0, input6B = 0, input6G = 0, cluster6total = 0;
    int input7R = 0, input7B = 0, input7G = 0, cluster7total = 0;
    int input8R = 0, input8B = 0, input8G = 0, cluster8total = 0;
    int input9R = 0, input9B = 0, input9G = 0, cluster9total = 0;
    int input10R = 0, input10B = 0, input10G = 0, cluster10total = 0;
    int input11R = 0, input11B = 0, input11G = 0, cluster11total = 0;
    int input12R = 0, input12B = 0, input12G = 0, cluster12total = 0;
    int input13R = 0, input13B = 0, input13G = 0, cluster13total = 0;
    int input14R = 0, input14B = 0, input14G = 0, cluster14total = 0;
    int input15R = 0, input15B = 0, input15G = 0, cluster15total = 0;
    
    // Saving all total calculations for each assigned clusters to calculate new ones
    for (int q = 0; q < 262144; q++){ // for each pixel
        if (input[q].ClusterAssigned == 0){
            input0R = input0R + input[q].r;
            input0G = input0G + input[q].g;
            input0B = input0B + input[q].b;
            cluster0total = cluster0total + 1 ;
        }
        else if (input[q].ClusterAssigned == 1){
            input1R = input1R + input[q].r;
            input1G = input1G + input[q].g;
            input1B = input1B + input[q].b;
            cluster1total = cluster1total +1;
        }
        else if (input[q].ClusterAssigned == 2){
            input2R = input2R + input[q].r;
            input2G = input2G + input[q].g;
            input2B = input2B + input[q].b;
            cluster2total=cluster2total+1;
               }
        else if (input[q].ClusterAssigned == 3){
            input3R = input3R + input[q].r;
            input3G = input3G + input[q].g;
            input3B = input3B + input[q].b;
            cluster3total = cluster3total+1;
               }
        else if (input[q].ClusterAssigned == 4){
            input4R = input4R + input[q].r;
            input4G = input4G + input[q].g;
            input4B = input4B + input[q].b;
            cluster4total = cluster4total+1 ;
               }
        else if (input[q].ClusterAssigned == 5){
            input5R = input5R + input[q].r;
            input5G = input5G + input[q].g;
            input5B = input5B + input[q].b;
            cluster5total = cluster5total+1;
               }
        else if (input[q].ClusterAssigned == 6){
            input6R = input6R + input[q].r;
            input6G = input6G + input[q].g;
            input6B = input6B + input[q].b;
            cluster6total = cluster6total+1;
               }
        else if (input[q].ClusterAssigned == 7){
            input7R = input7R + input[q].r;
            input7G = input7G + input[q].g;
            input7B = input7B + input[q].b;
            cluster7total = cluster7total +1;
               }
        else if (input[q].ClusterAssigned == 8){
            input8R = input8R + input[q].r;
            input8G = input8G + input[q].g;
            input8B = input8B + input[q].b;
            cluster8total = cluster8total +1;
               }
        else if (input[q].ClusterAssigned == 9){
            input9R = input9R + input[q].r;
            input9G = input9G + input[q].g;
            input9B = input9B + input[q].b;
            cluster9total = cluster9total+1;
               }
        else if (input[q].ClusterAssigned == 10){
            input10R = input10R + input[q].r;
            input10G = input10G + input[q].g;
            input10B = input10B + input[q].b;
            cluster10total = cluster10total +1;
               }
        else if (input[q].ClusterAssigned == 11){
            input11R = input11R + input[q].r;
            input11G = input11G + input[q].g;
            input11B = input11B + input[q].b;
            cluster11total = cluster11total+1;
               }
        else if (input[q].ClusterAssigned == 12){
            input12R = input12R + input[q].r;
            input12G = input12G + input[q].g;
            input12B = input12B + input[q].b;
            cluster12total = cluster12total +1;
               }
        else if (input[q].ClusterAssigned == 13){
            input13R = input13R + input[q].r;
            input13G = input13G + input[q].g;
            input13B = input13B + input[q].b;
            cluster13total = cluster13total +1;
               }
        else if (input[q].ClusterAssigned == 14){
            input14R = input14R + input[q].r;
            input14G = input14G + input[q].g;
            input14B = input14B + input[q].b;
            cluster14total = cluster14total +1;
               }
        else if (input[q].ClusterAssigned == 15){
            input15R = input15R + input[q].r;
            input15G = input15G + input[q].g;
            input15B = input15B + input[q].b;
            cluster15total = cluster15total +1;
        }
        else {
            cout << "";
               }
    }
        
    // Calculating new centers // and saving old ones for a comparison
    compare[0] = Cluster[0];
    Cluster[0].r = input0R / cluster0total;
    Cluster[0].g = input0G / cluster0total;
    Cluster[0].b = input0B / cluster0total;
  
    compare[1] = Cluster[1];
    Cluster[1].r = input1R / cluster1total;
    Cluster[1].g = input1G / cluster1total;
    Cluster[1].b = input1B / cluster1total;
    
    compare[2] = Cluster[2];
    Cluster[2].r = input2R / cluster2total;
    Cluster[2].g = input2G / cluster2total;
    Cluster[2].b = input2B / cluster2total;
    
    compare[3] = Cluster[3];
    Cluster[3].r = input3R / cluster3total;
    Cluster[3].g = input3G / cluster3total;
    Cluster[3].b = input3B / cluster3total;
    
    compare[4] = Cluster[4];
    Cluster[4].r = input4R / cluster4total;
    Cluster[4].g = input4G / cluster4total;
    Cluster[4].b = input4B / cluster4total;
    
    compare[5] = Cluster[5];
    Cluster[5].r = input5R / cluster5total;
    Cluster[5].g = input5G / cluster5total;
    Cluster[5].b = input5B / cluster5total;
    
    compare[6] = Cluster[6];
    Cluster[6].r = input6R / cluster6total;
    Cluster[6].g = input6G / cluster6total;
    Cluster[6].b = input6B / cluster6total;
    
    compare[7] = Cluster[7];
    Cluster[7].r = input7R / cluster7total;
    Cluster[7].g = input7G / cluster7total;
    Cluster[7].b = input7B / cluster7total;
    
    compare[8] = Cluster[8];
    Cluster[8].r = input8R / cluster8total;
    Cluster[8].g = input8G / cluster8total;
    Cluster[8].b = input8B / cluster8total;
    
    compare[9] = Cluster[9];
    Cluster[9].r = input9R / cluster9total;
    Cluster[9].g = input9G / cluster9total;
    Cluster[9].b = input9B / cluster9total;
    
    compare[10] = Cluster[10];
    Cluster[10].r = input10R / cluster10total;
    Cluster[10].g = input10G / cluster10total;
    Cluster[10].b = input10B / cluster10total;
    
    compare[11] = Cluster[11];
    Cluster[11].r = input11R / cluster11total;
    Cluster[11].g = input11G / cluster11total;
    Cluster[11].b = input11B / cluster11total;
    
    compare[12] = Cluster[12];
    Cluster[12].r = input12R / cluster12total;
    Cluster[12].g = input12G / cluster12total;
    Cluster[12].b = input12B / cluster12total;
    
    compare[13] = Cluster[13];
    Cluster[13].r = input13R / cluster13total;
    Cluster[13].g = input13G / cluster13total;
    Cluster[13].b = input13B / cluster13total;
    
    compare[14] = Cluster[14];
    Cluster[14].r = input14R / cluster14total;
    Cluster[14].g = input14G / cluster14total;
    Cluster[14].b = input14B / cluster14total;
    
    compare[15] = Cluster[15];
    Cluster[15].r = input15R / cluster15total;
    Cluster[15].g = input15G / cluster15total;
    Cluster[15].b = input15B / cluster15total;
    
    // 5. Keep looping through this until the clusters stop changing
    
    // 6. Then save the file with for each cluster assigned displays thats cluster for each point instead of the point value
        
        
    
        if(compare[0].r == Cluster[0].r && compare[0].g == Cluster[0].g && compare[0].b == Cluster[0].b &&
        compare[1].r == Cluster[1].r && compare[1].g == Cluster[1].g && compare[1].b == Cluster[1].b &&
        compare[2].r == Cluster[2].r && compare[2].g == Cluster[2].g && compare[2].b == Cluster[2].b &&
        compare[3].r == Cluster[3].r && compare[3].g == Cluster[3].g && compare[3].b == Cluster[3].b &&
        compare[4].r == Cluster[4].r && compare[4].g == Cluster[4].g && compare[4].b == Cluster[4].b &&
        compare[5].r == Cluster[5].r && compare[5].g == Cluster[5].g && compare[5].b == Cluster[5].b &&
        compare[6].r == Cluster[6].r && compare[6].g == Cluster[6].g && compare[6].b == Cluster[6].b &&
        compare[7].r == Cluster[7].r && compare[7].g == Cluster[7].g && compare[7].b == Cluster[7].b &&
        compare[8].r == Cluster[8].r && compare[8].g == Cluster[8].g && compare[8].b == Cluster[8].b &&
        compare[9].r == Cluster[9].r && compare[9].g == Cluster[9].g && compare[9].b == Cluster[9].b &&
        compare[10].r == Cluster[10].r && compare[10].g == Cluster[10].g && compare[10].b == Cluster[10].b &&
        compare[11].r == Cluster[11].r && compare[11].g == Cluster[11].g && compare[11].b == Cluster[11].b &&
        compare[12].r == Cluster[12].r && compare[12].g == Cluster[12].g && compare[12].b == Cluster[12].b &&
        compare[13].r == Cluster[13].r && compare[13].g == Cluster[13].g && compare[13].b == Cluster[13].b &&
        compare[14].r == Cluster[14].r && compare[14].g == Cluster[14].g && compare[14].b == Cluster[14].b &&
        compare[15].r == Cluster[15].r && compare[15].g == Cluster[15].g && compare[15].b == Cluster[15].b ){
        
        cout << "Program is Terminating with a total of " << repetitions << " repetitions " <<endl;
        saveClusterCentersToFile(input);
            for (int jk = 0; jk < 16; jk++){
                      cout << "Values for Cluster at END: " << jk << " : " <<  Cluster[jk].r << " " << Cluster[jk].g << " " << Cluster[jk].b << endl;
                }
                exit(0);
        
        }
        cout << "repetitions : " <<repetitions <<endl;;
        
        
        repetitions++;
    } // END OF FOREVER LOOP
    

    return 0;
}


bool readFile(dataHolder input[], string infilex)
{
ifstream infile(infilex);
   
    if(infile.fail()){
        return false;
    }
dataHolder k;
    int a = 0;
while(infile >> k.r){
    infile >> k.g >> k.b;
    input[a] = k;
    a++;
    if (a > 262144){
        break;}
}
infile.close();
return true;
}



int distance(double r1, double g1, double b1, double r2, double g2, double b2){
    int x = r1 - r2;
    int y = g1 - g2;
    int n = b1 - b2;
  
    int disCal=0;
    disCal = pow(x, 2) + pow(y, 2) + pow(n, 2);
    return disCal;
}



void saveClusterCentersToFile(dataHolder input[]){
 ofstream myfilez;
    
    myfilez.open(""); //Add destination on where to save
    myfilez << "P2" << endl;
    myfilez << "512 512" << endl;
    myfilez << "15" <<endl;

 for (int i = 0; i < 262144; i++){
    
     if (input[i].ClusterAssigned == 0){
         myfilez << " " << 0 << " " << 0 << " " << 0<<endl;
         //myfilez << " " << Cluster[0].r << " " << Cluster[0].g << " " << Cluster[0].b<<endl;
     }
     else if(input[i].ClusterAssigned == 1){
         myfilez << " " << 1 << " " << 1 << " " << 1<<endl;
         //myfilez << " " << Cluster[1].r << " " << Cluster[1].g << " " << Cluster[1].b<<endl;
     }
     else if(input[i].ClusterAssigned == 2){
         myfilez << " " << 2 << " " << 2 << " " << 2<<endl;
         //myfilez << " " << Cluster[2].r << " " << Cluster[2].g << " " << Cluster[2].b<<endl;
     }
     else if(input[i].ClusterAssigned == 3){
         myfilez << " " << 3 << " " << 3 << " " << 3<<endl;
         //myfilez << " " << Cluster[3].r << " " << Cluster[3].g << " " << Cluster[3].b<<endl;
         }
     else if(input[i].ClusterAssigned == 4){
         myfilez << " " << 4 << " " << 4 << " " << 4<<endl;
         //myfilez << " " << Cluster[4].r << " " << Cluster[4].g << " " << Cluster[4].b<<endl;
         }
     else if(input[i].ClusterAssigned == 5){
         myfilez << " " << 5 << " " << 5 << " " << 5<<endl;
         //myfilez << " " << Cluster[5].r << " " << Cluster[5].g << " " << Cluster[5].b<<endl;
         }
     else if(input[i].ClusterAssigned == 6){
         myfilez << " " << 6 << " " << 6 << " " << 6<<endl;
         //myfilez << " " << Cluster[6].r << " " << Cluster[6].g << " " << Cluster[6].b<<endl;
         }
     else if(input[i].ClusterAssigned == 7){
         myfilez << " " << 7 << " " << 7 << " " << 7<<endl;
         //myfilez << " " << Cluster[7].r << " " << Cluster[7].g << " " << Cluster[7].b<<endl;
         }
     else if(input[i].ClusterAssigned == 8){
         myfilez << " " << 8 << " " << 8 << " " << 8<<endl;
         //myfilez << " " << Cluster[8].r << " " << Cluster[8].g << " " << Cluster[8].b<<endl;
         }
     else if(input[i].ClusterAssigned == 9){
         myfilez << " " << 9 << " " << 9 << " " << 9<<endl;
         //myfilez << " " << Cluster[9].r << " " << Cluster[9].g << " " << Cluster[9].b<<endl;
         }
     else if(input[i].ClusterAssigned == 10){
        myfilez << " " << 10 << " " << 10 << " " << 10<<endl;
         //myfilez << " " << Cluster[10].r << " " << Cluster[10].g << " " << Cluster[10].b<<endl;
         }
     else if(input[i].ClusterAssigned == 11){
         myfilez << " " << 11 << " " << 11 << " " << 11<<endl;
         //myfilez << " " << Cluster[11].r << " " << Cluster[11].g << " " << Cluster[11].b<<endl;
     }
     else if(input[i].ClusterAssigned == 12){
         myfilez << " " << 12 << " " << 12 << " " << 12<<endl;
         //myfilez << " " << Cluster[12].r << " " << Cluster[12].g << " " << Cluster[12].b<<endl;
     }
     else if(input[i].ClusterAssigned == 13){
         myfilez << " " << 13 << " " << 13 << " " << 13<<endl;
         //myfilez << " " << Cluster[13].r << " " << Cluster[13].g << " " << Cluster[13].b<<endl;
     }
     else if(input[i].ClusterAssigned == 14){
         myfilez << " " << 14 << " " << 14 << " " << 14<<endl;
         //myfilez << " " << Cluster[14].r << " " << Cluster[14].g << " " << Cluster[14].b<<endl;
     }
     else if(input[i].ClusterAssigned == 15){
         myfilez << " " << 15 << " " << 15 << " " << 15<<endl;
         //myfilez << " " << Cluster[15].r << " " << Cluster[15].g << " " << Cluster[15].b<<endl;
     }
     else {
         cout <<"";
     }
     
 }
    
myfilez.close();
}

