package com.paris8.univ.androidproject.game;

/**
 * Created by Mzartek on 24/11/15.
 */
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
        return end-begin;
    }

    public static double getSeconds()
    {
        return (end - begin) / 1000.0;
    }

    public static double getMinutes()
    {
        return (end - begin) / 60000.0;
    }

    public static double getHours()
    {
        return (end - begin) / 3600000.0;
    }

    public static double getSeconds(long time)
    {
        return time / 1000.0;
    }

    public static double getMinutes(long time)
    {
        return time / 60000.0;
    }

    public static double getHours(long time)
    {
        return time / 3600000.0;
    }
}
