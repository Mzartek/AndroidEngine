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
}
