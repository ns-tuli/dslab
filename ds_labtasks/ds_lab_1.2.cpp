#include<bits/stdc++.h>
using namespace std;

int main (){


    string line;
    int n;
    vector<int>nums;

    getline(cin, line);
    istringstream stream(line);
    while (stream >> n )
    {
    nums.push_back(n);
    }

    int target;
    cin>>target;

    int x=nums.size();

   int arr[100000]={0};
   int index[100000]={0};

   for(int i=0;i<x;i++)
   {
        arr[nums[i]]++;
        index[nums[i]]=i;
   }

    int a,b,count=0;

    for(int i=0;i<100000;i++)
   {
       if(arr[i]!=0)
       {
            a=i;

            if(arr[target-i]>0 )
            {

                b=target-i;
                break;
            }
       }
   }

    for(int i=0;i<x;i++)
    {
        if(nums[i]==a)
        {
            cout<<i<<" ";break;
        }
    }

     for(int i=0;i<x;i++)
    {
        if(nums[i]==b)
        {
            cout<<i<<" "<<endl;break;
        }
    }

     for(int i=0;i<9;i++){
        if(arr[i]!=0 and arr[target-i]!=0){
                    if(i==target-i and arr[i]==1)
                    {
                            continue;
                    }

                count++;
        }
    }
    cout<<count/2<<endl;














}
