struct Student {
    int regNum;
    string name<>;
};

program REGISTRATION {
    version REGISTRATION_V1 {
        int REGISTER(Student) = 1;
    } = 1;
} = 0x30000001;
