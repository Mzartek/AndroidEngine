package com.paris8.univ.androidproject.game;

public final class Chronometer
{
    private static long begin, end;

    public static void start()
    {
        begin = System.currentTimeMillis();
    }

    public static void stop()
    {
        end = System.currentTimeMillis();
    }

    public static long getTime()
    {
        return end-begin;
    }

    public static long getMilliseconds()
    {
        return (end-begin);
    }

    public static long getSeconds()
    {
        return (long)((end - begin) / 1000.0);
    }

    public static long getMinutes()
    {
        return (long)((end - begin) / 60000.0);
    }

    public static long getHours()
    {
        return (long)((end - begin) / 3600000.0);
    }

    public static long getSeconds(long time)
    {
        return (long)(time / 1000.0);
    }

    public static long getMinutes(long time)
    {
        return (long)(time / 60000.0);
    }

    public static long getHours(long time)
    {
        return (long)(time / 3600000.0);
    }
}
