#pragma once

struct UpdateTimerSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "UpdateTimerSystem"
    };

    constexpr void operator()(entity& _entity, Timer& _timer) const noexcept
    {
        _timer.m_value -= 0.01f;
        if (_timer.m_value <= 0.0f)
        {
            (void)AddOrRemoveComponents<std::tuple<>, std::tuple<Timer>>(_entity);
        }
    }
};