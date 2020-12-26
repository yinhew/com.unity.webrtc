using Unity.Profiling;

namespace Unity.WebRTC.Runtime.Profiling
{
    public class Stats
    {
        public static readonly ProfilerCategory ProfilerCategory = ProfilerCategory.Scripts;

        public static readonly ProfilerCounter<float> EnemyCount =
            new ProfilerCounter<float>(ProfilerCategory, "Enemy Count 1", ProfilerMarkerDataUnit.Undefined);

        public static ProfilerCounterValue<int> BulletCount =
            new ProfilerCounterValue<int>(ProfilerCategory, "Bullet Count 1",
                ProfilerMarkerDataUnit.Count, ProfilerCounterOptions.FlushOnEndOfFrame);
    }
}
