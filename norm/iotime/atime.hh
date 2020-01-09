
struct atime {
  time_t stime;
  atime()
    : stime(time(0))
  {
  };
  ~atime()
  {
    std::cout << "et: " << time(0)-stime << " seconds" << std::endl;
  };
} timer;
