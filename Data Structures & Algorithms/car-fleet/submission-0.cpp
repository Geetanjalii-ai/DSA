class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {

        int n=pos.size();
        vector<double> time(n,0);

        vector<vector<int>> v;
        for(int i=0;i<pos.size();i++)
        {
            v.push_back({pos[i],sp[i]});
        }

        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a[0]>b[0];
        });

         int fleets=0;
         double lastT=0;
        for(int i=0;i<v.size();i++)
        {
            double t=(double)(target-v[i][0])/v[i][1];
            
            if(t>lastT)
            {
                fleets++;
                lastT=t;
            }
        }

       
       
        return fleets;
    }
};
