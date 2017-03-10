#ifndef ADS_KEY_VALUE_H
#define ADS_KEY_VALUE_H

#include <utility>

namespace ads
{
    template<typename Key,typename Value>
    class key_value : private std::pair<Key,Value>
    {
        using base = std::pair<Key,Value>;
    public:
        using key_type = Key;
        using value_type = Value;
        using base::pair;
        using base::operator=;
        ~key_value() = default;

        using reference = value_type &;
        using const_reference = const reference &;
        reference key() { return this->first; }
        const_reference key() const { return this->first; }
        reference value() { return this->second; }
        const_reference value() const { return this->second; }
    };

    template<typename Key,typename Value>
    constexpr key_value<Key,Value> make_kv(Key && key, Value && value)
    {
        return key_value<Key,Value>(std::move(key),std::move(value));
    }
}

#endif // ADS_KEY_VALUE_H
