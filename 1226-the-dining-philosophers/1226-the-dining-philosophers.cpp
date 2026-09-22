class DiningPhilosophers {
private:
    mutex m[5];
//saniya(2420491)
public:
    DiningPhilosophers() {
    }

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork
    ) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        // Lock lower-numbered fork first to avoid deadlock
        if (left < right) {
            m[left].lock();
            m[right].lock();
        } else {
            m[right].lock();
            m[left].lock();
        }

        // Pick up forks
        pickLeftFork();
        pickRightFork();

        // Eat
        eat();

        // Put down forks
        putLeftFork();
        putRightFork();

        // Unlock
        m[left].unlock();
        m[right].unlock();
    }
};