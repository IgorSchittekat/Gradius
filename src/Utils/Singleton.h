#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H

namespace util {

    template <typename T>
    class Singleton {
    public:
        /**
         * Deleted Copy Constructor
         */
        Singleton(const Singleton& rhs) = delete;

        /**
         * Deleted Copy Assignment
         */
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

    protected:
        /**
         * @brief Constructor
         */
        Singleton() = default;

    private:
        /**
         * @brief Only instance of T
         */
        static T* mInstance;
    };

    template <typename T>
    T* Singleton<T>::mInstance = nullptr;


} //namespace util

#endif //GRADIUS_SINGLETON_H
