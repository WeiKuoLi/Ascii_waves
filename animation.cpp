#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


string ascii_sample=" `.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
vector<double> brightness_sample{0, 0.0751, 0.0829, 0.0848, 0.1227, 0.1403, 0.1559, 0.185, 0.2183, 0.2417, 0.2571, 0.2852, 0.2902, 0.2919, 0.3099, 0.3192, 0.3232, 0.3294, 0.3384, 0.3609, 0.3619, 0.3667, 0.3737, 0.3747, 0.3838, 0.3921, 0.396, 0.3984, 0.3993, 0.4075, 0.4091, 0.4101, 0.42, 0.423, 0.4247, 0.4274, 0.4293, 0.4328, 0.4382, 0.4385, 0.442, 0.4473, 0.4477, 0.4503, 0.4562, 0.458, 0.461, 0.4638, 0.4667, 0.4686, 0.4693, 0.4703, 0.4833, 0.4881, 0.4944, 0.4953, 0.4992, 0.5509, 0.5567, 0.5569, 0.5591, 0.5602, 0.5602, 0.565, 0.5776, 0.5777, 0.5818, 0.587, 0.5972, 0.5999, 0.6043, 0.6049, 0.6093, 0.6099, 0.6465, 0.6561, 0.6595, 0.6631, 0.6714, 0.6759, 0.6809, 0.6816, 0.6925, 0.7039, 0.7086, 0.7235, 0.7302, 0.7332, 0.7602, 0.7834, 0.8037, 0.9999};
//todo
//map<double, char> ascii_map = create_map(brightness_sample, ascii_sample);

//todo
string render_image(vector<vector<double>> *mp){
    string image="";
    int n = (*mp).size(), m = (*mp)[0].size();
    vector<string> ascii_mp(n, "");
    int i, j;
    int resolution = ascii_sample.size();
    int brightness;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
	    brightness = min((int)((*mp)[i][j] * resolution), resolution-1);
	    ascii_mp[i] += ascii_sample[brightness];
	}
    	image += ascii_mp[i] + '\n';
    }
    
    return image;	
}
//done
vector<vector<double>>*  make_waves(int n, int m, double k, double w, double t){
    vector<vector<double>> *mp=new vector<vector<double>>(n,vector<double>(m, 0.0));
    int i, j;
    double r=0.0, phi =0.0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            r = sqrt((double)(pow(i-n/2, 2) + pow(j-m/2, 2)));
  	    phi = k * r - w * t;
	    (*mp)[i][j] = cos(phi) * cos(phi);
	}
    }
    return mp;
}
int main() {

    int num_frames = 100;
    double k = 1.0, w=2*M_PI, dt=0.01, t=0.0;
    int height=30, width=30;
    // Clear the terminal
    std::cout << "\x1b[2J";

    // Move cursor to the top-left corner
    std::cout << "\x1b[H";
    
    vector<string> frames(num_frames, "");
    
    for(auto &frame: frames){
        frame = render_image(make_waves(height, width, k, w, t));
        t += dt;
    }
    // Define the frames of the animation
    const char* test_frames[] = {
        "  ___\n"
        " /   \\\n"
        " |   |\n"
        " \\___/\n",
        
        "  _\n"
        " /_\\\n"
        "(o o)\n"
        " \\_/\n",

        "  ___\n"
        " /___\\\n"
        " |o o|\n"
        " \\_^_/\n",
        
        "  _\n"
        " /_\\_\n"
        "(o o )\n"
        " \\_/ |\n",

        "  ___\n"
        " /   \\\n"
        " |o o|\n"
        " \\_^_/\n"
    };

    int frame_index = 0;
    // Animation loop
    while (++frame_index) {
	frame_index %= num_frames;
        // Clear the terminal
        std::cout << "\x1b[2J";
        // Move cursor to the top-left corner
        std::cout << "\x1b[H";

        // Print the current frame
        std::cout << frames[frame_index];

        // Wait for a short time before displaying the next frame
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    return 0;
}

