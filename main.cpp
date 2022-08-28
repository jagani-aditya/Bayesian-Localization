#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Bayes
{
    public:
        double belief_door_open = 0.5;
        double belief_door_close = 0.5;

        double p_o_o = 0.6;
        double p_c_o = 0.4;

        double p_o_c = 0.2;
        double p_c_c = 0.8;

        double p_push_o_o = 1.0;
        double p_push_c_o = 0.0;
        double p_push_o_c = 0.8;
        double p_push_c_c = 0.2;

        double p_donothing_o_o = 1.0;
        double p_donothing_c_o = 0.0;
        double p_donothing_o_c = 0.0;
        double p_donothing_c_c = 1.0;
         

        double bel_dash_open, bel_dash_close, n; 

    void run(vector<string> actions, vector<string> measurements)
    {
        int N = actions.size();
        int i =0;
        while(i < N)
        {
            if(actions[i] == "do_nothing")
            {
                bel_dash_open = (p_donothing_o_o * belief_door_open) + (p_donothing_o_c * belief_door_close);
                bel_dash_close = 1 - bel_dash_open;
   
            }
            else if(actions[i] == "do_nothing")
            {
                bel_dash_open = (p_push_o_o * belief_door_open) + (p_push_o_c * belief_door_close);
                bel_dash_close = 1 - bel_dash_open;

            }
            
            if(measurements[i] == "open")
            {
                belief_door_open = p_o_o * bel_dash_open;
                belief_door_close = p_o_c * bel_dash_close;

            }
            else if(measurements[i] == "close")
            {
                belief_door_open = p_c_o * bel_dash_open;
                belief_door_close = p_c_c * bel_dash_close;

            }

            n = 1/(belief_door_open + belief_door_close);

            belief_door_open = n * belief_door_open;
            belief_door_close = n * belief_door_close;

            i+=1;

        }

        
        cout << "Current belief state (open): " << belief_door_open << endl;
        cout << "Current belief state (close): " << belief_door_close << endl;

    }

};


int main()
{
    Bayes obj;
    vector<string> actions{     "do_nothing","do_nothing","push",  "do_nothing","push", "do_nothing"};
    vector<string> measurements{"close",      "close",    "close", "close",     "open", "open"};
    


    obj.run(actions, measurements);

    return 0;
}