// Last updated: 11/2/2025, 10:27:19 PM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDevices = 0;

        int beams = 0;

        for(int i=0;i<bank.size();i++){
            string currFloor = bank[i];
            int frequency = std::count(currFloor.begin(), currFloor.end(), '1');
            beams += frequency*prevDevices;
            if(frequency>0){
                prevDevices = frequency;
            }
        }
        return beams;
    }
};