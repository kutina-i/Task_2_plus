#include "Queue.h"

int main()
{
    QueueArr queue(3);
    queue.put(0);
    queue.put(1);
    queue.put(2);
    try {
        queue.put(2);
    }
    catch (const std::exception&) {
        std::cout << "VSE HARASHO" << std::endl;
    }
    std::cout << queue.isEmpty() << std::endl;
    std::cout << queue.check() << std::endl;
    QueueArr queue1(3);
    queue1.put(0);
    queue1.put(1);
    queue1.put(2);
    QueueArr::Iterator it(queue1);
    it.start();
    for (int i = 0; i < 3; i++)
    {
        std::cout << it.getValue() << " ";
        it.next();
    }
    std::cout << it.finish() << std::endl;
    queue.clear();
    std::cout << queue.isEmpty() << std::endl;
    queue.put(33);
    std::cout << queue.take() << std::endl;
    std::cout << queue.isEmpty();
}
