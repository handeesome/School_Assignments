class Worker{
    private:
        int num;
        string name;
    public:
        Worker(int, string);
        friend ostream& operator<<(ostream& out, Worker &);

}
