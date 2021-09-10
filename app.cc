#include <stdio.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <thread>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<pair<string, vector<string>>> gojuonlist = {
{"あ", {"a"}},
{"い", {"i"}},
{"う", {"u"}},
{"え", {"e"}},
{"お", {"o"}},
{"か", {"ka"}},
{"き", {"ki"}},
{"く", {"ku"}},
{"け", {"ke"}},
{"こ", {"ko"}},
{"さ", {"sa"}},
{"し", {"si", "shi"}},
{"す", {"su"}},
{"せ", {"se"}},
{"そ", {"so"}},
{"た", {"ta"}},
{"ち", {"ti", "chi"}},
{"つ", {"tu", "tsu"}},
{"て", {"te"}},
{"と", {"to"}},
{"な", {"na"}},
{"に", {"ni"}},
{"ぬ", {"nu"}},
{"ね", {"ne"}},
{"の", {"no"}},
{"は", {"ha"}},
{"ひ", {"hi"}},
{"ふ", {"hu", "fu"}},
{"へ", {"he"}},
{"ほ", {"ho"}},
{"ま", {"ma"}},
{"み", {"mi"}},
{"む", {"mu"}},
{"め", {"me"}},
{"も", {"mo"}},
{"や", {"ya"}},
{"ゆ", {"yu"}},
{"よ", {"yo"}},
{"ら", {"ra"}},
{"り", {"ri"}},
{"る", {"ru"}},
{"れ", {"re"}},
{"ろ", {"ro"}},
{"わ", {"wa"}},
{"ゐ", {"wi"}},
{"ゑ", {"we"}},
{"を", {"wo"}},
{"ん", {"n"}},
};

bool done = false;
int finished = 0;
int total = gojuonlist.size();
int error = 0;

void verify(pair<string, vector<string>> item){
    printf("\033[1;37mGOJUON TEST\033[0m\tfinished \033[0;33m%d\033[0m/%d\terror \033[0;31m%d\033[0m\t \033[10;;93m(%s)\033[0m\n", finished, total, error, "press enter to next test");
    printf("\033[1;33m%s\033[0m Roma spell is:", item.first.c_str());
    string answer;
    char c;
    while((c=getchar()) !='\n'){
        answer += c;
    }
    bool isright = false;
    for(string ans : item.second){
        if(ans == answer){
            isright = true;
            printf("\033[1;32m%s/%s\033[0m right!!!\n", item.first.c_str(), answer.c_str());
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            break;
        }
    }
    if(not isright){
        printf("wrong answer \033[1;31m%s/%s\033[0m , correct one is \033[1;32m%s/%s\033[0m\n", item.first.c_str(),
                answer.c_str(), item.first.c_str(), item.second[0].c_str());
        error += 1;
        cin.get();
    }
    finished += 1;
    done = true;
}

void shuffle(){
    for(int i=0;i<total;i++){
        int j = rand()%total;
        std::swap(gojuonlist[i], gojuonlist[j]);
     //   auto temp = gojuonlist[i];
     //   gojuonlist[i] = gojuonlist[j];
     //   gojuonlist[j] = temp;
    }
}

int main(){
    shuffle();
    int cnt = 0;
    for(auto &item : gojuonlist){
        thread t1(verify, item);
        t1.join();
        while(not done and cnt < 30){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            cnt += 1;
        }
        system("clear");
        done = false;
        cnt = 0;
    }
    return 0;
}
