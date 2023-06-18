//
//Runtime 56
//Memory Usage 33

class ParkingSystem {
    int idx[3];
public:
    ParkingSystem(int big, int medium, int small): idx{big, medium, small} {
        
    }
    
    bool addCar(int carType) {
        if(--idx[carType - 1] < 0)
            return false;
        return true;  
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */