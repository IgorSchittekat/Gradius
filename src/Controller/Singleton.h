#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H

namespace ctrl {

    template <typename T>
    class Singleton {
    public:

        static T* getInstance() {
            if (!m_instance) {
                m_instance = new T();
            }
            return m_instance;
        }

        Singleton(const Singleton &rhs) = delete;
        Singleton &operator=(const Singleton &rhs) = delete;
        ~Singleton() = default;

    private:
        static T* m_instance;

    private:
        Singleton() = default;

    };

    template <typename T>
    T* Singleton<T>::m_instance = nullptr;


} //namespace ctrl

#endif //GRADIUS_SINGLETON_H
