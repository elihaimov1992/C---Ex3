#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Member{
    private:
        int numOfFollowers;
        int numOfFollowing;
        
        static int numOfMembers;
        
        vector <Member*> following;
        vector <Member*> followers;
        
        
    public:
    
        static int count(){ return numOfMembers; }
    
        int numFollowers();
        int numFollowing();
        void follow(Member& member);
        void unfollow(Member& member);
        void unfollow2(Member* member);
        bool compare(Member* a, Member* b);
        bool isFollowing(Member* member);
        bool isFollowedBy(Member* member);
        void tempUnfollow(Member* member);
        void unFollowAll();
        void deleteAllFollowers();
        Member();
        ~Member();

};


    
    


        
