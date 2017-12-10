#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H

namespace util {

    template <typename T>
    class Singleton {
    public:
        Singleton(const Singleton& rhs) = delete;
        Singleton& operator=(const Singleton& rhs) = delete;
        /**
         * @brief get only instance of T
         * @return only instance of T
         */
        static T* getInstance() {
            if (!mInstance) {
                mInstance = new T();
            }
            return mInstance;
        }

    private:
        static T* mInstance;

    protected:
        /**
         * @brief private constructor
         */
        Singleton() = default;
    };

    template <typename T>
    T* Singleton<T>::mInstance = nullptr;


} //namespace util

#endif //GRADIUS_SINGLETON_H
