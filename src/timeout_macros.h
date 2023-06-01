#ifndef TIMEOUT_MACROS_H_
#define TIMEOUT_MACROS_H_
#ifdef __cplusplus
extern "C" {
#endif

#define wait_timeout(expr, timeout, err_return)                                \
    {                                                                          \
        int volatile hacky_timer = timeout;                                    \
        while (expr && --hacky_timer) {                                        \
        }                                                                      \
        if (0 == hacky_timer) {                                                \
            return err_return;                                                 \
        }                                                                      \
    }

#ifdef __cplusplus
}
#endif
#endif // TIMEOUT_MACROS_H_
