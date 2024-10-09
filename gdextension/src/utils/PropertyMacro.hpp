namespace IT_Utils
{
    #define PROPERTY(type, name) \
        protected: \
            type name; \
        public: \
            inline type get_##name() { return name; } \
            inline void set_##name(const type& new_value) { name = new_value; } \
}